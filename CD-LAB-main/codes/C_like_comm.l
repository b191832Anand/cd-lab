/*Definition Section*/
%{
#include<stdio.h>
%}


/*Rule Section*/

%%

\/\/(.*) {};					

\/\*(.*\n)*.*\*\/  {};			
%%

/*call the yywrap function*/
int yywrap()
{
return 1;
}



/*Auxiliary function*/
/*Driver function*/

int main()
{
yyin=fopen("input.c","r");
yyout=fopen("output.c","w");
/*call the yylex function.*/
yylex();
return 0;
}

