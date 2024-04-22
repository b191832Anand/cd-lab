%{
#include<stdio.h>
%}
%%
">"|"<"|"<="|">="|"!=" {printf("relational operator = %s",yytext);}
.* {printf("wrong input");}
%%
int yywrap(){}
int main()
{
	yylex();
}
