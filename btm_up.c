#include <stdio.h>
#include <string.h>

char a[16], ac[20], stk[15], act[10];

    int k = 0, i = 0, j = 0, c,z=0;
void check(int c);

int main() {
    
    printf("GRAMMAR is:\nE -> E+E\nE -> E*E\nE -> (E)\nE -> id\n");
    printf("Enter input string: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0; // Remove trailing newline
    
    c = strlen(a);
    strcpy(act, "SHIFT->");
    printf("Stack\tInput\tAction\n");

    for (k = 0, i = 0; j < c; k++, i++, j++) {
        if (a[j] == 'i' && a[j+1] == 'd') {
            stk[i] = a[j];
            stk[i+1] = a[j+1];
            stk[i+2] = '\0';
            a[j] = ' ';
            a[j+1] = ' ';
            printf("\n$%s\t%s$\t%ssid", stk, a, act);
            check(c);
        } else {
            stk[i] = a[j];
            stk[i+1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%ssymbols", stk, a, act);
            check(c);
        }
    }

    return 0;
}

void check(int c) {
    //int z;
    strcpy(ac, "REDUCE TO E");

    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z+1] == 'd') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            j++;
        }
    }

    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z+1] == '+' && stk[z+2] == 'E') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i=i-2;
        } else if (stk[z] == 'E' && stk[z+1] == '*' && stk[z+2] == 'E') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i=i-2;            
        } else if (stk[z] == '(' && stk[z+1] == 'E' && stk[z+2] == ')') {
            stk[z] = 'E';
            stk[z+1] = '\0';
            stk[z+2] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i=i-2;
        }
    }
}

