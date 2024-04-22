%{
#include<stdio.h>
int lc=1,sc=0,tc=0,wc=0,c=0,ch=0;
%}

%%
\n {lc++;}
\t  {tc++;}
([ ]) {sc++;}
. {ch++;c++;}
[a-zA-Z0-9]+ {wc++;c=c+yyleng;}
%%
int yywrap(){}
int main()
{
	yylex();
	printf("\nline count = %d\n",lc);
	printf("space count = %d\n",sc);
	printf("tab count = %d\n",tc);
	printf("character count = %d\n",c);
	printf("words count = %d\n",(wc+ch));
}
