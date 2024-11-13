%{
#include <stdio.h>
#include <stdbool.h>

extern FILE *yyin;
FILE *outputFile;
int commentCount = 0;
bool inBlockComment = false;
%}

%%
"/*"            { inBlockComment = true; commentCount++; }
"*/"            { inBlockComment = false; }
"//".*\n        { commentCount++; }  /* Single line comment */

\n              { 
                    if (inBlockComment) {
                        commentCount++;  /* Count additional lines in block comments */
                    } else if (!inBlockComment) {
                        fprintf(outputFile, "\n");
                    }
                }

.               { if (!inBlockComment) fprintf(outputFile, "%s", yytext); }

%%

int main() {
    FILE *inputFile = fopen("1.c", "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    outputFile = fopen("output.c", "w");
    if (!outputFile) {
        perror("Error creating output file");
        fclose(inputFile);
        return 1;
    }

    yyin = inputFile;
    yylex();  /* Run lexical analysis */

    fclose(inputFile);
    fclose(outputFile);

    printf("Number of comment lines: %d\n", commentCount);
    return 0;
}

int yywrap() {
    return 1;
}