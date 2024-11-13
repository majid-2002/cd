#include<stdio.h>
#include<string.h>

struct operation {
    char left;
    char right[20];
};

struct operation operations[10], optimized[10];

int main() {
    int numOperations, optimizedCount = 0;

    printf("Enter the number of values: ");
    scanf("%d", &numOperations);

    // Input operations
    for (int i = 0; i < numOperations; i++) {
        printf("left: ");
        scanf(" %c", &operations[i].left);
        printf("right: ");
        scanf("%s", operations[i].right);
    }

    // Display intermediate code
    printf("Intermediate code: \n");
    for (int i = 0; i < numOperations; i++) {
        printf("%c = %s\n", operations[i].left, operations[i].right);
    }

    // Dead code elimination
    for (int i = 0; i < numOperations - 1; i++) {
        char temp = operations[i].left;
        for (int j = 0; j < numOperations; j++) {
            if (strchr(operations[j].right, temp)) {
                optimized[optimizedCount].left = operations[i].left;
                strcpy(optimized[optimizedCount].right, operations[i].right);
                optimizedCount++;
                break;
            }
        }
    }

    // Adding the last operation (it might be necessary in the final output)
    optimized[optimizedCount].left = operations[numOperations - 1].left;
    strcpy(optimized[optimizedCount].right, operations[numOperations - 1].right);
    optimizedCount++;

    printf("\nAfter dead code elimination: \n");
    for (int i = 0; i < optimizedCount; i++) {
        printf("%c = %s\n", optimized[i].left, optimized[i].right);
    }

    // Removing duplicate right-side expressions
    for (int i = 0; i < optimizedCount; i++) {
        for (int j = i + 1; j < optimizedCount; j++) {
            if (strcmp(optimized[i].right, optimized[j].right) == 0) {
                optimized[j].left = '\0'; // Mark for removal
            }
        }
    }

    // Display optimized code
    printf("Optimized code\n");
    for (int i = 0; i < optimizedCount; i++) {
        if (optimized[i].left != '\0') {
            printf("%c = %s\n", optimized[i].left, optimized[i].right);
        }
    }

    return 0;
}

