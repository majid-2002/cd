#include <stdio.h>
#include <string.h>

typedef struct DFA {
    int nos;                     // Number of states
    int noi;                     // Number of input symbols
    int nof;                     // Number of final states
    int delta[10][10];           // Transition table
    int final[10];               // Array of final states
    char inputSymbols[10];       // Array of input symbols
} DFA;

// Function to check the position of the input symbol in the inputSymbols array
int checkSymbol(char ch, DFA d) {
    for (int i = 0; i < d.noi; i++) {
        if (ch == d.inputSymbols[i]) {
            return i;
        }
    }
    return -1;
}

// Function to check if a given state is a final state
int checkFinalState(int st, DFA d) {
    for (int i = 0; i < d.nof; i++) {
        if (st == d.final[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    DFA d;
    
    // Input DFA details
    printf("Enter number of states: ");
    scanf("%d", &d.nos);
    printf("Enter number of final states: ");
    scanf("%d", &d.nof);
    printf("Enter number of input symbols: ");
    scanf("%d", &d.noi);

    for (int i = 0; i < d.noi; i++) {
        printf("Enter input symbol: ");
        scanf(" %c", &d.inputSymbols[i]);
    }

    for (int i = 0; i < d.nof; i++) {
        printf("Enter final state no %d: ", i + 1);
        scanf("%d", &d.final[i]);
    }

    // Input the transition table
    printf("\nEnter transitions:\n");
    for (int i = 0; i < d.nos; i++) {
        for (int j = 0; j < d.noi; j++) {
            printf("d(q%d, %c): ", i, d.inputSymbols[j]);
            scanf("%d", &d.delta[i][j]);
        }
    }

    // Display the transition table
    printf("\nTransition Table:\n");
    for (int i = 0; i < d.noi; i++) {
        printf("\t %c", d.inputSymbols[i]);
    }
    printf("\n");

    for (int i = 0; i < d.nos; i++) {
        printf("q%d", i);
        for (int j = 0; j < d.noi; j++) {
            printf("\tq%d", d.delta[i][j]);
        }
        printf("\n");
    }

    // Checking strings in the DFA
    do {
        char string[10];
        printf("\nEnter a string (or type 'exit' to quit): ");
        scanf("%s", string);

        // Exit condition
        if (strcmp(string, "exit") == 0) {
            break;
        }

        int statecounter = 0;
        int flag = 1;

        for (int i = 0; i < strlen(string); i++) {
            int sympos = checkSymbol(string[i], d);
            if (sympos == -1) {  // Symbol not in alphabet
                flag = 0;
                break;
            }
            statecounter = d.delta[statecounter][sympos];
        }

        if (flag == 1 && checkFinalState(statecounter, d) == 1) {
            printf("%s is accepted.\n", string);
        } else {
            printf("%s is not accepted.\n", string);
        }
    } while (1);

    return 0;
}


/*#include <stdio.h>
#include <string.h>


typedef struct DFA{
	int nos;
	int noi;
	int nof;
	int delta[10][10];
	int finalState[10];
	char inputSymbol[10];
	}DFA;

int symbolPosn(char ch,DFA d){
	for(int i=0;i<d.noi;i++){
		if(d.inputSymbol[i]==ch)
			return i;
	}
	return -1;
}

int isFinal(int f,DFA d){
	for(int i=0;i<d.nof;i++){
		if(f==d.finalState[i])
			return 1;
	}
	return 0;
}

int main(){
	DFA d;
	printf("Enter nof,noi,nos,input symbols,final states");
	scanf("%d%d%d",&d.nof,&d.noi,&d.nos);
	for(int i=0;i<d.noi;i++){
		scanf("%c",&d.inputSymbol[i]);
		}
	for(int i=0;i<d.nof;i++){
		scanf("%d",&d.finalState[i]);
		}
		
	printf("Enter transitions:");
	for(int i=0;i<d.nos;i++){
		for(int j=0;j<d.noi;j++){
			printf("d(q%d,%c)",i,d.inputSymbol[j]);
			scanf("%d",&d.delta[i][j]);
		}
	}
	
	
	
	printf("\nTransition table:\n");
	for(int i=0;i<d.noi;i++){
		printf("\t%c",d.inputSymbol[i]);
	}
	printf("\n");
	
	for(int i=0;i<d.nos;i++){
		printf("q%d",i);
		for(int j=0;i<d.noi;j++){
			printf("\t%d",d.delta[i][j]);
		}
		printf("\n");
	}
	
	
	
	do{
		char string[10]; 
		printf("Enter the string(enter exit to exit");
		scanf("%s",&string);
		
		if(strcmp(string,"exit")==0){
			break;
		}
		
		int flag=1;
		int stateCounter=0;
		
		for(int i=0;i<strlen(string);i++){
			int symPosn=symbolPosn(string[i],d);
			if(symPosn==-1){
				flag=0;
				break;
				}
			stateCounter=d.delta[stateCounter][symPosn];
		}
		
		if(flag==1&&isFinal(stateCounter,d)==1)
			printf("valid dfa");
		else
			printf("invalid dfa");
	}while(1);
	
	return 0;
					
}







*/










