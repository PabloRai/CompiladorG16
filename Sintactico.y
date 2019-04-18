%{
#include <stdio.h>
#include <stdlib.h>

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
%token EQUALS_OPERATOR
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
%start program


%type <integer_value> INTEGER_CONSTANT
%type <float_value> FLOAT_CONSTANT
%type <string_value> STRING_CONSTANT


%union {
  int integer_value;
  float float_value;
  char string_value[20];
}

%%


program: {printf("STARTING COMPILATION\n");} variable_declaration_block {printf("\nSUCCESSFUL COMPILATION\n");}
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
   variable_list {printf(" VARIABLE_LIST ");} SEMICOLON {printf(";");} ID {printf(" ID ");}
  | ID {printf(" ID ");}
  ;

%%

int main(int argc, char *argv[]) {
	yyin = fopen(argv[1], "r");;
	do {
		yyparse();
	} while(!feof(yyin));
	return 0;
}
void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
