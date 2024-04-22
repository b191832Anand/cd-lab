%{
int lineCount = 0;
int wordCount = 0;
int charCount = 0;
%}

%%
\n            { lineCount++; }
[a-zA-Z]+     { wordCount++; charCount += strlen(yytext); }
.             { charCount++; }
%%
int yywrap(){};
int main() {
    yylex();
    printf("Number of lines: %d\n", lineCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of characters: %d\n", charCount);
    return 0;
}

