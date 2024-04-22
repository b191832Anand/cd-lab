%{
	#include<stdio.h>
	int l;
%}
%%
[a-zA-Z0-9]+ {l=yyleng;fun(l);}
\n return 0;
%%
 fun(int l)
{
	if(yytext[0]=='a')
		if(l==3)
		{
			printf("\n%s starts with a and length is equal to 3\n",yytext);
		}
}
int yywrap(){}
int main()
{
	yylex();
	return 0;
	}
