%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"

#define YYDEBUG 1
extern int yylex();
extern int yyparse();
extern yylineno;
extern FILE* yyin;
void yyerror(const char* s);
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

%union {
  int integer_value;
  float float_value;
  char string_value[20];
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

assignment: identification ASSIGNMENT_OPERATOR expression;

while_loop: WHILE {printf(" WHILE ");} OPENING_PARENTHESIS {printf(" ( ");} condition CLOSING_PARENTHESIS {printf(" ) ");} OPENING_KEY {printf(" { ");} algorithms {printf(" ALGORITHM ");} CLOSING_KEY {printf(" } ");};

for_loop: FOR identification ASSIGNMENT_OPERATOR expression TO expression INTEGER_CONSTANT algorithms NEXT identification
  | FOR identification ASSIGNMENT_OPERATOR expression TO expression algorithms NEXT identification
  ;

display: DISPLAY identification
  | DISPLAY constant
  ;

get: GET identification;

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

factor: identification
  | constant
  | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS
  ;

constant: INTEGER_CONSTANT {printf("INTEGER_CONSTANT %d", $1);}
  | FLOAT_CONSTANT {printf("FLOAT_CONSTANT %f", $1);}
  | STRING_CONSTANT {printf("STRING_CONSTANT %s", $1);}
  ;

variable_declaration_block: DEFVAR {printf("DEFVAR\n");} variable_declarations ENDDEF {printf("\nENDDEF\n");}
  ;

variable_declarations:
   variable_declarations variable_declaration
  | variable_declaration

variable_declaration: variable_type COLON {printf(":");} variable_list {printf("VARIABLE_LIST");}
  ;
variable_type:
   INT_TYPE {printf(" INT_TYPE ");}
  | FLOAT_TYPE {printf(" FLOAT_TYPE ");}
  | STRING_TYPE {printf(" STRING_TYPE ");}
  ;
variable_list:
   variable_list {printf(" VARIABLE_LIST ");} SEMICOLON {printf(";");} identification {printf(" ID ");}
  | identification
  ;

identification: ID {printf(" ID %s ", $1);};


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
	return 0;
}
void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
