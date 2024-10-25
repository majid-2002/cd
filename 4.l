%{
#include <stdio.h>
extern FILE *yyin; 
%}
%%
[ \n\t]         ;
.               { printf("%s", yytext); }
%%

int main() {
    FILE *fp;
    fp = fopen("1.c", "r");
    if (!fp) { 
        perror("Error opening file");
        return 1;
    }
    yyin = fp; 
    yylex(); 
    fclose(fp);
    return 0;
}

int yywrap() {
    return 1;
}
