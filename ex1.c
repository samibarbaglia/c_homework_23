/** #include <stdio.h>

int main()
{

    float bus_price;
    float taxi_price;
    float money;
    int choice;

    printf("Enter price of bus: \n");
    scanf("%f", &bus_price);
    printf("\nEnter price of taxi: \n");
    scanf("%f", &taxi_price);

    printf("\nPlease enter your money amount:\n");
    scanf("%f", &money);

    while (money >= 0) {
        printf("You have %.2f euros left. \n", money);

        if (money >= bus_price && taxi_price) {
            printf("\nWould you like to take: \n"
                   "(1) bus (%.2f euros)\n"
                   "(2) taxi (%.2f euros)\n", bus_price, taxi_price);
            printf("\nENTER TRANSPORTATION: ");
            scanf("%d", &choice);

            if (choice != 1 && choice != 2) {
                printf("\nPLEASE CHOOSE TRANSPORT\n");
            }
            else if (choice == 1) {
                if (money < bus_price) {
                    printf("\nYou cannot afford bus \n");
                }
                else if (money >= bus_price) {
                    money = money - bus_price;
                    printf("\nYou chose the bus\n");
                }
            }
            else if (choice == 2) {
                if (money >= taxi_price) {
                    money = money - taxi_price;
                    printf("\nYou chose taxi\n");
                }
                else if (money < taxi_price) {
                    printf("\nYou cannot afford taxi\n");
                }

            }
        }
        else if (money < bus_price && taxi_price) {
            printf("\nYOU NEED TO WALK HOME\n");
            break;
        }
    }
} **/