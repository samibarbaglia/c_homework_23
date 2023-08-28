// I had help from milja with this exercise
#include <stdio.h>

int main() {
    float tax_rate;
    float income_limit;
    float tax_over;
    int i;
    float month[12];
    float tax[12];
    float total_income;

    printf("Enter tax rate: \n");
    scanf("%f", &tax_rate);
    printf("Enter income limit: \n");
    scanf("%f", &income_limit);
    printf("Enter tax rate for income over the limit: \n");
    scanf("%f", &tax_over);

    for (i = 0; i < 12; i++) {
        printf("Enter income for month %d: \n", i + 1);
        scanf("%f", &month[i]);
        total_income = total_income + month[i];

        if(income_limit > total_income) {
            tax[i] = month[i] * (tax_rate / 100);
        }
        else if (total_income - income_limit < month[i]) {
            float over_limit = total_income - income_limit;
            float under_limit = month[i] - over_limit;
            tax [i] = (under_limit * (tax_rate / 100)) + (over_limit * (tax_over / 100));
        }
        else {
            tax[i] = month[i] * (tax_over / 100);
            total_income = total_income + month[i];
        }
    }

    printf("\n%10s %10s %10s\n", "month", "income", "taxes");
    for (i = 0; i < 12; i++) {
        printf("%10d %10.2f %10.2f\n", i+1, month[i], tax[i]);
    }
    return 0;
}