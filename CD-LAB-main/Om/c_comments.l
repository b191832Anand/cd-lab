%{
#include<stdio.h>
#include<stdlib.h>
%}
%%
\/\/(.*) {};
\/\*(.*\n)*.*\*\/ {};
%%
int yywrap(){}
int main()
{
	yyin=fopen("saichandu.c","r");
	yyout=fopen("pine.c","w");
	yylex();
}
