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

void loginAsAdmin() {
    char email[50];
    char password[50];

    printf("Enter email: ");
    scanf("%s", email);
    printf("Enter password: ");
    scanf("%s", password);

    if(strcmp(email, "csc099g1@gmail.com") == 0 && strcmp(password, "0000") == 0) {
        printf("Login successful!\n");
        int choice;
        char id[50];
        printf("1. Generate Report\n2. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        	case 1:
            	printf("Enter customer id: ");
            	scanf("%s", id);
            	for(int i = 0; i < customerCount; i++) {
                	if(strcmp(customers[i].id, id) == 0) {
                    	printf("Customer found!\n");
                    	generateRep();
                    	return;
                	}
						
					else{
						printf("Customer not found!\n");
					}
			case 2:
				return;
        		}
   	 	} 
	}
}

void loginAsCustomer() {
    char id[50];
    char password[50];
    int choice, choice_2;
    

    printf("Enter id: ");
    scanf("%s", id);
    printf("Enter password: ");
    scanf("%s", password);

    for(int i = 0; i < customerCount; i++) {
        if(strcmp(customers[i].id, id) == 0 && strcmp(customers[i].password, password) == 0) {
            printf("Login successful!\n");
            printf("1. Personal Information\n2. Ticket Booking\n3. F&B Booking\n4. Loyalty Point\n5. Feedback\n6. Back\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice){
            	
            case 1:
			    editPI(i);
			    break;
			case 2:
				 break;
			case 3:
				 break;
			case 4:
				 break;
			case 5:
				Feedback();
				break;
			case 6:
				return;
            }
            
        }
    }
    printf("Invalid credentials!\n");
}

void generateRep(){
	
	}

void registerAsCustomer() {
    printf("Enter id: ");
    scanf("%s", customers[customerCount].id);
    printf("Enter password: ");
    scanf("%s", customers[customerCount].password);
    customerCount++;
    printf("Registration successful!\n");
}

void editPI(i){
	char firstName [50];
	char lastName [50];
	int choice = 0;
	
	printf("1. Edit\n2. View\n3. Back");
	switch (choice){
		case 1:
			printf("Please enter your personal information: ");
		 	printf("First name: ");
	    	scanf("%s", firstName);
	        printf("Last name: ");
	        scanf("%s", lastName);
	        strcpy(customers[i].fullName, firstName);
	        strcat(customers[i].fullName, " ");        // add a space
	    	strcat(customers[i].fullName, lastName);
	    	printf("Phone number: ");
	        scanf("%s", customers[i].phoneNum);
	    	printf("Email adress: ");
	        scanf("%s", customers[i].email);
	        printf("Nationality: ");
	        scanf("%s", customers[i].nationality);
	        printf("Identification Number: ");
	        scanf("%s", customers[i].IDCard);
	        printf("Information updated!\n");
	        break;
	    case 2:
		    viewPI();
						
		case 3:
			return;		
		}
	}

void viewPI(){
	int i;
		    printf("Name: %s \n", customers[i].fullName);
		    printf("Phone Number: %s\n", customers[i].phoneNum);
			printf("Email Address: %s\n", customers[i].email);
		    printf("Nationality: %s\n", customers[i].nationality);
		    printf("Identification Number: %s\n", customers[i].id);
	}
	
void Feedback(){
	int i;
            printf("Please enter your feedback:\n  ");
            scanf("%s", customers[i].feedback);
            printf("Thank you for taking the time to provide us with your valuable feedback. We greatly appreciate your input as it helps us improve our services and ensure a better experience for all our visitors.");
	}
