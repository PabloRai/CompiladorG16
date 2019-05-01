%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol.h"
#include "tree.h"
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

ast* tree;
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
%type <ast> expression
%type <ast> term
%type <ast> factor
%type <ast> assignment
%type <ast> comparation
%type <ast> condition
%type <ast> get
%type <ast> display
%type <ast> for_loop
%type <ast> algorithms
%type <ast> algorithm
%type <ast> while_loop
%type <ast> decision
%type <ast> sentence
%type <ast> program
%type <auxLogicOperator> logic_operator

%union {
  int integer_value;
  float float_value;
  char string_value[30];
  struct treeNode* ast;
  char* auxLogicOperator;
}

%%


program: sentence {printf("\nSUCCESSFUL COMPILATION\n"); $$ = $1; tree = $$;}
  ;

sentence: sentence algorithm {$$ = $2;}
  | variable_declaration_block {}
  ;

algorithms: algorithm {$$ = $1;}
  | algorithms algorithm {$$ = newNode("CUERPO_ALGORITMH", $1, $2);}
  ;

algorithm: decision {$$ = $1;}
  | assignment {$$ = $1;}
  | while_loop {$$ = $1;}
  | for_loop {$$ = $1;}
  | display {$$ = $1;}
  | get {$$ = $1;}
  ;

decision: IF OPENING_PARENTHESIS condition CLOSING_PARENTHESIS OPENING_KEY algorithms CLOSING_KEY {$$ = newNode("IF", $3, $6);};

assignment: ID ASSIGNMENT_OPERATOR expression {validateIdIsDeclared($1); $$ = newNode("=", newLeaf($1), $3);};

while_loop: WHILE OPENING_PARENTHESIS condition CLOSING_PARENTHESIS OPENING_KEY algorithms CLOSING_KEY {$$ = newNode("WHILE", $3, $6);};

for_loop: FOR ID ASSIGNMENT_OPERATOR expression TO expression INTEGER_CONSTANT algorithms NEXT ID {
    compareIdentificators($2, $10);
    $$ = newNode("FOR", newNode("=", newLeaf($2), newNode("FOR_OPCIONAL", newNode("TO", $4, $6), newLeaf(getSymbolName(&($7),1)))), newNode("CUERPO_FOR", $8, newNode("NEXT", newLeaf($2), NULL)));
    }
  | FOR ID ASSIGNMENT_OPERATOR expression TO expression algorithms NEXT ID {
    compareIdentificators($2, $9);
    $$ = newNode("FOR", newNode("=", newLeaf($2), newNode("TO", $4, $6)), newNode("CUERPO_FOR", $7, newNode("NEXT", newLeaf($2), NULL)));
    }
  ;

display: DISPLAY ID {validateIdIsDeclared($2); $$ = newNode("DISPLAY", newLeaf($2), NULL);}
  | DISPLAY INTEGER_CONSTANT {$$ = newNode("DISPLAY",newLeaf(getSymbolName(&($2),1)), NULL);}
  | DISPLAY FLOAT_CONSTANT {$$ = newNode("DISPLAY",newLeaf(getSymbolName(&($2),2)), NULL);}
  | DISPLAY STRING_CONSTANT {$$ = newNode("DISPLAY",newLeaf(getSymbolName(&($2),3)), NULL);}
  ;

get: GET ID {$$ = newNode("GET", newLeaf($2), NULL);};

condition: comparation {$$ = $1;}
  | comparation logic_operator comparation {$$ = newNode($2, $1, $3);}
  | NOT_LOGIC_OPERATOR comparation {$$ = newNode("!", $2, NULL);}
  ;

comparation: expression  logic_operator  expression {$$ = newNode($2, $1, $3);}
  ;

logic_operator: EQUALS_LOGIC_OPERATOR {$$ = "=";}
  | NOT_EQUALS_LOGIC_OPERATOR {$$ = "!=";}
  | GREATER_LOGIC_OPERATOR {$$ = ">";}
  | GREATER_OR_EQUAL_LOGIC_OPERATOR {$$ = ">=";}
  | LOWER_LOGIC_OPERATOR {$$ = "<";}
  | LOWER_OR_EQUAL_LOGIC_OPERATOR {$$ = "<=";}
  ;

expression: expression SUM_OPERATOR term {$$ = newNode("+", $1, $3);}
  | expression MINUS_OPERATOR term {$$ = newNode("-", $1, $3);}
  | term {$$ = $1;}
  ;

term: term MULTIPLIER_OPERATOR factor {$$ = newNode("*", $1, $3);}
  | term DIVIDE_OPERATOR factor {$$ = newNode("/", $1, $3);}
  | factor {$$ = $1;}
  ;

factor: ID {$$ = newLeaf($1);}
  | INTEGER_CONSTANT {$$ = newLeaf(getSymbolName(&($1),1));}
  | FLOAT_CONSTANT {$$ = newLeaf(getSymbolName(&($1),2));}
  | STRING_CONSTANT {$$ = newLeaf(getSymbolName($1,3));}
  | OPENING_PARENTHESIS expression CLOSING_PARENTHESIS {$$ = $2;}
  ;



variable_declaration_block: DEFVAR variable_declarations ENDDEF
  ;

variable_declarations:
   variable_declarations variable_declaration
  | variable_declaration

variable_declaration: variable_type COLON variable_list {putTypeIdentifierOnSymbolTable(currentIdentifierDeclarationType);}
  ;
variable_type:
   INT_TYPE {saveIdentifierDeclarationType($1);}
  | FLOAT_TYPE {saveIdentifierDeclarationType($1);}
  | STRING_TYPE {saveIdentifierDeclarationType($1);}
  ;
variable_list:
   variable_list SEMICOLON ID {insertIdentifier($3);} 
  | ID {insertIdentifier($1);}
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
  printf("\n --- INTERMEDIA --- \n");
  printAST(tree);
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
