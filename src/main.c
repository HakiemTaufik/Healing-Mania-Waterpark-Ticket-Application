#include <stdio.h>
#include <string.h>

typedef struct {
    char id[50];
    char password[50];
    char fullName[100];
    char phoneNum[50];
    char email[50];
    char nationality[50];
    char IDCard[50];
    char feedback [250];
} Customer;

Customer customers[100]; // array to hold customers
int customerCount = 0; // keeps track of the number of customers

int main() {
    while(1) {
        printf("1. Administrator\n2. Customer\n3.Exit\n");
printf("Enter your choice: ");
int choice;
scanf("%d", &choice);

switch(choice) {
    case 1:
        loginAsAdmin();
        break;
    case 2: {
        printf("1. Login\n2. Register\n");
        printf("Enter your choice: ");
        int customerChoice;
        scanf("%d", &customerChoice);
        if(customerChoice == 1) {
            loginAsCustomer();
        } else if(customerChoice == 2) {
            registerAsCustomer();
        } else {
            printf("Invalid choice!\n");
        }
        break;
    }
    case 3:
        printf("Exiting program...\n");
        return 0;
    default:
        printf("Invalid choice!\n");
        break;
    }
}
return 0;
}
