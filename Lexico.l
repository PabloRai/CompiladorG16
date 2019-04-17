

DIGIT [0-9]
INTEGER_CONSTANT [0-9]+
LETTER [a-zA-Z]
WHILE "while"
IF "if"
FOR "for"
DEFVAR "DEFVAR"
ENDDEF "ENDDEF"
FLOAT "FLOAT"
INT "INT"
STRING "STRING"
NEXT "NEXT"
TO "TO"
DISPLAY "DISPLAY"
GET "GET"
COMMENT "/*".*"*/"
STRING_CONSTANT  \".*\"
ID [a-zA-Z]([a-zA-Z]|[0-9])*
SPACE " "
OPENING_PARENTHESIS "("
CLOSING_PARENTHESIS ")"
SUM_OPERATOR "+"
MINUS_OPERATOR "-"
DIVIDE_OPERATOR "/"
MULTIPLIER_OPERATOR "*"
EQUALS_OPERATOR "=="
ASSIGNMENT_OPERATOR ":="
OPENING_KEY "{"
CLOSING_KEY "}"
SEMICOLON ";"
COLON ":"


%%

{SPACE} {printf("SPACE \n");}
{DIGIT} {printf("DIGIT: "); ECHO; printf("\n");}
{INTEGER_CONSTANT} {printf("INTEGER_CONSTANT: "); ECHO; printf("\n");}
{STRING_CONSTANT} {printf("INTEGER_CONSTANT: "); checkStringConstantLimits(); printf("\n");}
{ID} {printf("ID: "); ECHO; printf("\n");}
{COMMENT} {printf("COMMENT"); ECHO; printf("\n");}
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
