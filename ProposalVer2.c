#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

const char* studentChecker(bool isStudent) {
    return isStudent ? "Enrolled in NU Lipa" : "Not enrolled in NU Lipa";
}

int main() {
    FILE *fptr;
    bool isStudent = false;
    char choiceYorN[10];
    char choiceYorN2[10];
    char surname_Name[40];
    char first_Name[40];
    char middle_Name[40];
    char email_User[50];
    char location[50];
    char contactNum[30];
    int age = 0;
    int choice;
    
    printf("Are you a Student of NU Lipa: (YES or NO): "); 
    fgets(choiceYorN2, sizeof(choiceYorN2), stdin);
    choiceYorN2[strcspn(choiceYorN2, "\n")] = '\0';

    if (strcasecmp(choiceYorN2, "yes") == 0) {
        isStudent = true;
        printf("\nYou are a student of NU Lipa!\n");
    } else {
        printf("\nYou are not a student of NU Lipa. Exiting program...\n");
        return 0; // exits program immediately
    }
    
    printf("\nCreate a Student Account... \n");
    printf("1. Continue\n");
    printf("2. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    getchar(); 
    
    switch (choice) {
        case 1:
            do { // must have 10+ CHARACTERS
                printf("Enter your surname: ");
                fgets(surname_Name, sizeof(surname_Name), stdin);
                surname_Name[strcspn(surname_Name, "\n")] = '\0'; 
            } while (strlen(surname_Name) < 0);
            
            do{
                printf("Enter your first name: ");
                fgets(first_Name, sizeof(first_Name), stdin);
                first_Name[strcspn(first_Name, "\n")] = '\0'; 
            } while (strlen(first_Name) < 0);
            
            do{
                printf("Enter your middle name: ");
                fgets(middle_Name, sizeof(middle_Name), stdin);
                middle_Name[strcspn(middle_Name, "\n")] = '\0'; 
            } while (strlen(middle_Name) < 0);
            
            printf("Enter your age: "); // Enter the user's age
            scanf("%d", &age);
            getchar(); 
            
            if (age <= 17) {
                printf("You must consult with your parents to use this feature... Continue if present\n");
                return 1;
            }
            
            printf("Enter your email: ");
            fgets(email_User, sizeof(email_User), stdin);
            email_User[strcspn(location, "\n")] = '\0';
            
            printf("Please type your address: "); // Enter the user's add
            fgets(location, sizeof(location), stdin);
            location[strcspn(location, "\n")] = '\0';
            
            printf("Contact Info:  ex:(+63 0123 454 7327)"); // Enter the user's contact
            fgets(contactNum, sizeof(contactNum), stdin);

            break;
            
        case 2:
            printf("You have successfully exited.\n");
            return 0;
            
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    
    char fullName[130];
    snprintf(fullName, sizeof(fullName), "%s, %s %s", surname_Name, first_Name, middle_Name);
     
    printf("=================================\n");
    printf("Name     : %s\n", fullName);
    printf("Age      : %d\n", age);
    printf("Location : %s\n", location);
    printf("Email    : %s\n", email_User);
    printf("Contact  : %s\n", contactNum);
    printf("Status   : %s\n", studentChecker(isStudent));
    
    char filename[100];
    snprintf(filename, sizeof(filename), "C:/Users/GianRossBCorpuz/Desktop/userdata_%s.txt", fullName);
    
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(fptr, "Name     : %s\n", fullName);
    fprintf(fptr, "Age      : %d\n", age);
    fprintf(fptr, "Location : %s\n", location);
    fprintf(fptr, "Contact  : %s\n", contactNum);
    fprintf(fptr, "Status   : %s\n", studentChecker(isStudent));
    
    fclose(fptr);
    printf("Text has been saved to userdata.txt\n");
    
    char line[100];
    printf("\nReading saved data:\n");
    while (fgets(line, sizeof(line), fptr)) {
    printf("%s", line);
    }
    
    return 0;
}
