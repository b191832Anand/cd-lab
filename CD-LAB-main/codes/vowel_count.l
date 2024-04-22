%{
#include<stdio.h>
int vowelCount = 0;
%}

%%
[aAeEiIoOuU]   { vowelCount++; }
.              { /* Ignore other characters */ }
\n             { printf("Number of vowels: %d\n", vowelCount); vowelCount = 0; }
%%
int yywrap(){};
int main() {
    yylex();
    return 0;
}

