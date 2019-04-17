
%{
  #include  <float.h>
%}
digit [0-9]

letter [a-zA-Z]
while "WHILE"
if "IF"
for "for"
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
semicolon ";"
colon ":"


%%

{space} {printf("space \n");}
{digit} {printf("digit: "); ECHO; printf("\n");}
{integer_constant} {printf("INTEGER_CONSTANT: "); ECHO; printf("\n");}
{string_constant} {printf("STRING_CONSTANT: "); checkStringConstantLimits(); printf("\n");}
{float_constant} {printf("FLOAT_CONSTANT: "); checkFloatConstantLimits(); printf("\n");}
{id} {printf("ID: "); ECHO; printf("\n");}
{comment} {printf("COMMENT"); ECHO; printf("\n");}
{assignment_operator} {printf("ASSIGNMENT_OPERATOR"); ECHO; printf("\n");}
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
