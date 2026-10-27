#include <stdio.h>

int main(void)
{
    int stock;
    int customers;
    int total_sold = 0;
    int rejected = 0;

    printf("Enter initial stock quantity: ");
    if (scanf("%d", &stock) != 1 || stock < 0) {
        printf("Invalid stock quantity.\n");
        return 1;
    }

    printf("Enter number of customers: ");
    if (scanf("%d", &customers) != 1 || customers < 0) {
        printf("Invalid number of customers.\n");
        return 1;
    }

    for (int i = 0; i < customers; i++) {
        int requested;

        printf("Enter quantity requested by customer %d: ", i + 1);
        if (scanf("%d", &requested) != 1 || requested < 0) {
            printf("Invalid requested quantity.\n");
            return 1;
        }

        if (requested <= stock) {
            stock -= requested;
            total_sold += requested;
        } else {
            printf("Insufficient Stock\n");
            rejected++;
        }
    }

    printf("\nTotal units sold: %d\n", total_sold);
    printf("Rejected transactions: %d\n", rejected);
    printf("Remaining stock: %d\n", stock);

    return 0;
}