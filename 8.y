%{
	#include<stdio.h>
%}
%token num
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
start : E {printf("%d",$$);}
E : E '+' E {$$ = $1 + $3;} |
	E '-' E {$$ = $1-$3;} |
	E '' E {$$ = $1$3;} |
	E '/' E {$$ = $1/$3;} |
	num {$$ = $1;};
%%
int yyerror(){
	printf("Invalid error");
}
int main(){
	yyparse();
}