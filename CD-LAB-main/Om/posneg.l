%{
#include<stdio.h>
int a;
%}
%%
[+-]?[0-9]+ {a=atoi(yytext);
		if(a>0)
		printf("positive");
		else if(a<0)
		printf("negative");
		else
		printf("equal to zero");}
.* {printf("error");}
%%
int yywrap(){}
int main()
{
	yylex();
}
