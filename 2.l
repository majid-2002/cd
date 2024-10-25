%{
    int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
#.* {printf("\n\t%s is a preprocessor directive",yytext);}
int|float|double|goto|swich|void|continue|break|if|else|return|struct|for {printf("\n\t%s is a keyword",yytext);}
"\*" {COMMENT=1; printf("\n\t%s is a comment",yytext);}
{identifier}\( {if(!COMMENT)printf("\t\nFunction %s",yytext);}
\{ {if(!COMMENT)printf("\t\nBlock begins");}
\} {if(!COMMENT)printf("\t\nBlock ends");}
{identifier}(\[[0-9]*\])? {if(!COMMENT)printf("\n\t%s is an identifier",yytext);}
\".*\" {if(!COMMENT)printf("\n\t%s is a string",yytext);}
[0-9]* {if(!COMMENT)printf("%s is a number",yytext);}
\)(\:)? {if(!COMMENT)printf("\n\t");ECHO;printf("\n");}
\( ECHO;
= {if(!COMMENT)printf("\n\t%s is an assignment operator",yytext);}
\<|\>|\<=|\>=|== {if(!COMMENT)printf("\n\t%s is a relational operator",yytext);}
%%
int main(){
    FILE* fp;
    fp=fopen("1.c","r");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(0);
    }
    yyin=fp;
    yylex();
    printf("\n");
    return 0;
}
int yywrap(){
    return 1;
}