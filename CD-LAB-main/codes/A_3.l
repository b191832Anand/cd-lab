%{
int in_word = 0;
%}

%%
[A-Za-z]+ {
    if (strlen(yytext) == 3 && yytext[0] == 'A') {
        printf("%s\n", yytext);
    }
}
.|\n       { /* Ignore other characters */ }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}

