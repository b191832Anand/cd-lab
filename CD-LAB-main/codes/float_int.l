%{
int intCount = 0;
int floatCount = 0;
%}

%%
[0-9]+               { intCount++; }
[0-9]+"."[0-9]+      { floatCount++; }
[0-9]+"."[0-9]*      { floatCount++; }
"."[0-9]+            { floatCount++; }
.                    { /* Ignore other characters */ }
%%
int yywrap(){};
int main() {
    yylex();
    printf("Number of integers: %d\n", intCount);
    printf("Number of floating point numbers: %d\n", floatCount);
    return 0;
}

