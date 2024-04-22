%{
	int f=0,c=0;
%}
%%
[0-9]+"."[0-9] {f++;}
[0-9]+ {c++;};
%%
int yywrap(){}
int main()
{
	yylex();
	printf("float = %d\n",f);
	printf("interger = %d",c);
}
