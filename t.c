#include <stdio.h>
#include <string.h>

char input[100];
int i = 0, error = 0;

void E();
void Eds();
void T();
void Tds();
void F();

int main() {
    printf("Recursive descent parsing for grammar:\n");
    printf("E -> T E'\nE' -> + T E' | ε\nT -> F T'\nT' -> * F T' | ε\nF -> ( E ) | id\n");

    printf("Enter input string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from fgets
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    E();

    if (input[i] == '\0' && error == 0) {
        printf("String is accepted\n");
    } else {
        printf("String is rejected\n");
    }

    return 0;
}

void E() {
    T();
    Eds();
}

void Eds() {
    if (input[i] == '+') {
        i++;
        T();
        Eds();
    }
}

void T() {
    F();
    Tds();
}

void Tds() {
    if (input[i] == '*') {
        i++;
        F();
        Tds();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            error = 1;  // Missing closing parenthesis
        }
    } else if (input[i] == 'i') {  // Assuming 'id' is represented by 'i'
        i++;
    } else {
        error = 1;  // Unexpected character
    }
}

