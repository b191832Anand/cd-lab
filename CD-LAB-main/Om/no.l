%{
#include<stdio.h>
int l;
%}
%%
[a-zA-Z0-9]+ {l=yyleng;
			printf("length = %d",l);}
.* {printf("error");}
%%
int yywrap(){}
int main()
{
	printf("enter string:");
	yylex();
}

