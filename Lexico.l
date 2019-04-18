
%{
  #include  <float.h>
%}

while "WHILE"
if "IF"
for "FOR"
defvar "DEFVAR"
enddef "ENDDEF"
float "FLOAT"
int "INT"
string "STRING"
next "NEXT"
to "TO"
display "DISPLAY"
get "GET"
comment "*/"(.*|\n|\r)"/*"
float_constant [0-9]+"."[0-9]+
string_constant  \".*\"
integer_constant [0-9]+
id [a-zA-Z]([a-zA-Z]|[0-9])*
space " "
opening_parenthesis "("
closing_parenthesis ")"
sum_operator "+"
minus_operator "-"
divide_operator "/"
multiplier_operator "*"
equals_operator "=="
assignment_operator ":="
opening_key "{"
closing_key "}"
opening_square_bracket "["
closing_square_bracket "]"
semicolon ";"
colon ":"


%%

{while} {printf("WHILE: "); ECHO; printf("\n");}
{if} {printf("IF: "); ECHO; printf("\n");}
{for} {printf("FOR: "); ECHO; printf("\n");}
{defvar} {printf("DEFVAR: "); ECHO; printf("\n");}
{enddef} {printf("ENDDEF: "); ECHO; printf("\n");}
{float} {printf("FLOAT: "); ECHO; printf("\n");}
{int} {printf("INT: "); ECHO; printf("\n");}
{string} {printf("STRING: "); ECHO; printf("\n");}
{next} {printf("NEXT: "); ECHO; printf("\n");}
{to} {printf("TO: "); ECHO; printf("\n");}
{display} {printf("DISPLAY: "); ECHO; printf("\n");}
{get} {printf("GET: "); ECHO; printf("\n");}
{closing_parenthesis} {printf("CLOSING_PARENTHESIS: "); ECHO; printf("\n");}
{opening_parenthesis} {printf("OPENING_PARENTHESIS: "); ECHO; printf("\n");}
{closing_key} {printf("CLOSING_KEY: "); ECHO; printf("\n");}
{opening_key} {printf("OPENING_KEY: "); ECHO; printf("\n");}
{opening_square_bracket} {printf("OPENING_SQUARE_BRACKET: "); ECHO; printf("\n");}
{closing_square_bracket} {printf("CLOSING_SQUARE_BRACKET: "); ECHO; printf("\n");}
{space} {printf("space \n");}
{integer_constant} {printf("INTEGER_CONSTANT: "); ECHO; printf("\n");}
{string_constant} {printf("STRING_CONSTANT: "); checkStringConstantLimits(); printf("\n");}
{float_constant} {printf("FLOAT_CONSTANT: "); checkFloatConstantLimits(); printf("\n");}
{id} {printf("ID: "); ECHO; printf("\n");}
{comment} {printf(" COMMENT: "); ECHO; printf("\n");}
{assignment_operator} {printf("ASSIGNMENT_OPERATOR: "); ECHO; printf("\n");}
{sum_operator} {printf("SUM_OPERATOR: "); ECHO; printf("\n");}
{minus_operator} {printf("MINUS_OPERATOR: "); ECHO; printf("\n");}
{multiplier_operator} {printf("MULTIPLIER_OPERATOR: "); ECHO; printf("\n");}
{divide_operator} {printf("DIVIDE_OPERATOR: "); ECHO; printf("\n");}
{equals_operator} {printf("EQUALS_OPERATOR: "); ECHO; printf("\n");}
{semicolon} {printf("SEMICOLON: "); ECHO; printf("\n");}
{colon} {printf("COLON: "); ECHO; printf("\n");}





. {printf("WTF IS THIS MAN\n");}
<<EOF>> {yyterminate();}

%%
main() {
  yylex();
}

checkStringConstantLimits() {
  if (yyleng > 30) {
    printf("Exceeded token\n");
  } else {
    ECHO;
  }
}

checkFloatConstantLimits() {
  if (atof(yytext) > FLT_MAX || yyleng > 39) {
    printf("Exceeded token float\n");
  } else {
    ECHO;
  }
}
