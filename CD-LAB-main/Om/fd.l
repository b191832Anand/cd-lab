%{
	#include<stdio.h>
	int f=0,d=0;
%}
%%
[0-9]+"."[0-9]+ {f++;}
[0-9]+ {d++;}
%%
int yywrap(){}
int main()
{
	printf("enter digits:");
	yylex();
	printf("\ndecimal digits = %d",f);
	printf("integer digits = %d",d);
	
}
