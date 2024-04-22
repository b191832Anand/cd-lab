%{
int a;
%}
%%
[0-9]+ {a=atoi(yytext);
 if(a%2==0)
		printf("even");
		else
		printf("odd");}
%%
int yywrap(){}
int main()
{
	yylex();
}
