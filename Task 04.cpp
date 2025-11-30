#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    printf("Enter initial number of days (N): ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid number of days.\n");
        return 1;
    }

    double *sales = (double *)malloc(N * sizeof(double));
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    double total = 0.0;
    for (int i = 0; i < N; i++) {
        printf("Enter sales for day %d: ", i + 1);
        if (scanf("%lf", &sales[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            free(sales);
            return 1;
        }
        total += sales[i];
    }

    printf("\nTotal sales for %d days: %.2f\n", N, total);

    int M;
    printf("\nDo you want to add more days? Enter number of additional days (0 for none): ");
    if (scanf("%d", &M) != 1) {
        printf("Invalid input.\n");
        free(sales);
        return 1;
    }

    if (M > 0) {
    	
        double *temp = (double *)realloc(sales, (N + M) * sizeof(double));
        if (temp == NULL) {
            
            printf("Re-allocation failed. Keeping original data.\n");
            free(sales);
            return 1;
        }
        sales = temp; 

       
        for (int i = N; i < N + M; i++) {
            printf("Enter sales for day %d: ", i + 1);
            if (scanf("%lf", &sales[i]) != 1) {
                printf("Invalid input. Exiting.\n");
                free(sales);
                return 1;
            }
            total += sales[i];
        }

        N = N + M; 
        printf("\nAfter adding %d days, total sales for %d days: %.2f\n", M, N, total);
    } else {
        printf("\nNo extra days added. Final total remains: %.2f\n", total);
    }

    printf("\nAll sales values:\n");
    for (int i = 0; i < N; i++) {
        printf("Day %2d: %.2f\n", i + 1, sales[i]);
    }

    free(sales);
    return 0;
}

