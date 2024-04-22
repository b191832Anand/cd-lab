%{
	#include<stdio.h>
	int v=0;
	int c=0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {c++;}
%%
yywrap(){};
int main()
{
	printf("enter a string:");
	yylex();
	printf("vowel count = %d\n",v);
	printf("consonant count = %d\n",c);
}
	
