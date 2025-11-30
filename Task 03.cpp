#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    getchar();

    char **strings = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char temp[1000];

        printf("Enter string %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        temp[strcspn(temp, "\n")] = '\0';

        strings[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));

        strcpy(strings[i], temp);
    }

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                char *temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }

    // Output sorted strings
    printf("\nSorted Strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}

