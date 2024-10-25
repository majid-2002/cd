%{
#include<stdio.h>
int vowels = 0, cons = 0;
%}


%%
[aeiouAEIOU] {vowels++; }
[\t ] {ECHO;}
. {cons++;}
%%

int main() {
    yylex();
    printf("\n%d vowels , %d consonants \n", vowels, cons);
    return 0;
}

int yywrap(){
    return 1;
}