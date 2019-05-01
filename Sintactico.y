%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"
#include <string.h>

#define YYDEBUG 1
extern int yylex();
extern int yyparse();
extern yylineno;
extern FILE* yyin;
void yyerror(const char* s);
void saveIdentifierDeclarationType();
char currentIdentifierDeclarationType[7];
void validateIdIsDeclared();
void compareIdentificators();
%}





%token WHILE
%token IF
%token FOR
%token DEFVAR
%token ENDDEF
%token INT_TYPE
%token FLOAT_TYPE
%token STRING_TYPE
%token NEXT
%token TO
%token DISPLAY
%token GET
%token COMMENT
%token FLOAT_CONSTANT
%token STRING_CONSTANT
%token INTEGER_CONSTANT
%token ID
%token OPENING_PARENTHESIS
%token CLOSING_PARENTHESIS
%token ASSIGNMENT_OPERATOR
%token OPENING_KEY
%token CLOSING_KEY
%token OPENING_SQUARE_BRACKET
%token CLOSING_SQUARE_BRACKET
%token SEMICOLON
%token COLON
%left SUM_OPERATOR
%left MINUS_OPERATOR
%left DIVIDE_OPERATOR
%left MULTIPLIER_OPERATOR
%left EQUALS_LOGIC_OPERATOR
%left NOT_EQUALS_LOGIC_OPERATOR
%left NOT_LOGIC_OPERATOR
%left GREATER_LOGIC_OPERATOR
%left GREATER_OR_EQUAL_LOGIC_OPERATOR
%left LOWER_LOGIC_OPERATOR
%left LOWER_OR_EQUAL_LOGIC_OPERATOR
%start program


%type <integer_value> INTEGER_CONSTANT
%type <float_value> FLOAT_CONSTANT
%type <string_value> STRING_CONSTANT
%type <string_value> ID
%type <string_value> INT_TYPE
%type <string_value> STRING_TYPE
%type <string_value> FLOAT_TYPE

%union {
  int integer_value;
  float float_value;
  char string_value[30];
}

%%


program: sentence {printf("\nSUCCESSFUL COMPILATION\n");}
  ;

sentence: sentence algorithm {printf(" SENTENCE ALGORITHM ");}
  | variable_declaration_block {printf(" VARIABLE DECLARATION ");}
  ;

algorithms: algorithm
  | algorithms algorithm
  ;

algorithm: decision {printf(" DECISION ");}
  | assignment {printf(" ASSIGNMENT ");}
  | while_loop {printf(" WHILE LOOP ");}
  | for_loop {printf(" FOR LOOP ");}
  | display {printf(" DISPLAY ");}
  | get {printf(" GET ");}
  ;

decision: IF {printf(" IF ");} OPENING_PARENTHESIS {printf(" ( ");} condition CLOSING_PARENTHESIS {printf(" ) ");} OPENING_KEY {printf(" { ");} algorithms {printf(" ALGORITHM ");} CLOSING_KEY {printf(" } ");};

assignment: ID ASSIGNMENT_OPERATOR {printf(" := ");} expression {validateIdIsDeclared($1);};

while_loop: WHILE {printf(" WHILE ");} OPENING_PARENTHESIS {printf(" ( ");} condition CLOSING_PARENTHESIS {printf(" ) ");} OPENING_KEY {printf(" { ");} algorithms {printf(" ALGORITHM ");} CLOSING_KEY {printf(" } ");};

for_loop: FOR ID ASSIGNMENT_OPERATOR expression TO expression INTEGER_CONSTANT algorithms NEXT ID {compareIdentificators($2, $10);}
  | FOR ID ASSIGNMENT_OPERATOR expression TO expression algorithms NEXT ID {compareIdentificators($2, $9);}
  ;

display: DISPLAY ID {validateIdIsDeclared($2);}
  | DISPLAY INTEGER_CONSTANT {printf(" %d", $2);}
  | DISPLAY FLOAT_CONSTANT {printf(" %f", $2);}
  | DISPLAY STRING_CONSTANT {printf(" %s", $2);}
  ;

get: GET ID;

condition: comparation {printf(" comparation ");}
  | comparation logic_operator comparation
  | NOT_LOGIC_OPERATOR comparation
  ;

comparation: expression {printf(" expression1 ");} logic_operator {printf(" logic operator ");} expression {printf(" expression2 ");}
  ;

logic_operator: EQUALS_LOGIC_OPERATOR
  | NOT_EQUALS_LOGIC_OPERATOR
  | GREATER_LOGIC_OPERATOR
  | GREATER_OR_EQUAL_LOGIC_OPERATOR
  | LOWER_LOGIC_OPERATOR
  | LOWER_OR_EQUAL_LOGIC_OPERATOR
  ;

expression: expression SUM_OPERATOR term
  | expression MINUS_OPERATOR term
  | term
  ;

term: term MULTIPLIER_OPERATOR factor
  | term DIVIDE_OPERATOR factor
  | factor
  ;

factor: ID
  | INTEGER_CONSTANT {printf(" %d", $1);}
  | FLOAT_CONSTANT {printf(" %f", $1);}
  | STRING_CONSTANT {printf(" %s", $1);}
  | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS
  ;



variable_declaration_block: DEFVAR {printf("DEFVAR\n");} variable_declarations ENDDEF {printf("\nENDDEF\n");}
  ;

variable_declarations:
   variable_declarations variable_declaration
  | variable_declaration

variable_declaration: variable_type COLON {printf(":");} variable_list {putTypeIdentifierOnSymbolTable(currentIdentifierDeclarationType);}
  ;
variable_type:
   INT_TYPE {printf(" %s", $1); saveIdentifierDeclarationType($1);}
  | FLOAT_TYPE {printf(" %s", $1); saveIdentifierDeclarationType($1);}
  | STRING_TYPE {printf(" %s", $1); saveIdentifierDeclarationType($1);}
  ;
variable_list:
   variable_list SEMICOLON ID {printf(";  %s ", $3); insertIdentifier($3);} 
  | ID {printf("  %s ", $1); insertIdentifier($1);}
  ;


%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");
  yydebug = 0;
  printf("STARTING COMPILATION\n");
  symbolTable = NULL;
	do {
		yyparse();
	} while(!feof(yyin));
  printTable();
  saveTable();
	return 0;
}
void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s on line %d\n", s, yylineno);
	exit(1);
}

void saveIdentifierDeclarationType(char* identiferName) {
  strcpy(currentIdentifierDeclarationType, identiferName);
}

void validateIdIsDeclared(char* id) {
  symbolNode* symbol = findSymbol(id);
  if (symbol == NULL || symbol->type == NULL) {
    fprintf(stderr, "\nVariable: %s is not declared on the declaration block on line %d\n", id, yylineno);
    exit(1);
  }
}

void compareIdentificators(char* firstIdentificator, char* secondIdentificator) {
  if (strcmp(firstIdentificator, secondIdentificator) != 0) {
    fprintf(stderr, "\n Identificators are not the same, line: %d\n", yylineno);
    exit(1);
  }
}
