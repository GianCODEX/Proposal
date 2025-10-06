#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

const char* studentChecker(bool isStudent) {
    return isStudent ? "Enrolled in NU Lipa" : "Not enrolled in NU Lipa";
}

void inputString(char *prompt, char *buffer, int size, int minLen){
    do{
        printf("%s", prompt);
        fgets(buffer, size, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) < minLen){
            printf("Input must be at least %d character(s). Please try again.\n", minLen);
        }
    } while (strlen(buffer) < minLen);
}

bool isValidEmailDomain(const char *email) {
    const char *gmail = "@gmail.com";
    const char *yahoo = "@yahoo.com";
    size_t len = strlen(email);

    if (len >= strlen(gmail) && strcmp(email + len - strlen(gmail), gmail) == 0) {
        return true;
    }
    if (len >= strlen(yahoo) && strcmp(email + len - strlen(yahoo), yahoo) == 0) {
        return true;
    }
    return false;
}

void inputEmail(char *prompt, char *buffer, int size) {
    do {
        printf("%s", prompt);
        fgets(buffer, size, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (!isValidEmailDomain(buffer)) {
            printf("Email must end with @gmail.com or @yahoo.com \n");
        } else if (strlen(buffer) < 6) { // basic length check, e.g. "a@b.co"
            printf("Email is too short. Please try again.\n");
        } else {
            break;
        }
    } while (true);
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
    int age;
    int choice;
    int editChoice;
    
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
    
    if (choice != 1){
        printf("You have successfully exited.\n");
        return 0;
    }
    
    inputString("Enter your surname: ", surname_Name, sizeof(surname_Name), 1);
    inputString("Enter your first name: ", first_Name, sizeof(first_Name), 1);
    inputString("Enter your middle name: ", middle_Name, sizeof(middle_Name), 1);
    
    do {
        printf("Enter your age: ");
        scanf("%d", &age);
        if (age <= 0) {
            printf("Age must be a positive number. Please try again.\n");
        }
    } while (age <= 0);
    
    inputEmail("Enter your email: ", email_User, sizeof(email_User));
    inputString("Please type your address: ", location, sizeof(location), 1);
    inputString("Contact Info: ex:(+63 0123 454 7327): ", contactNum, sizeof(contactNum), 5);
    
    while(true){
        printf("\n=================================\n");
        printf("\nPlease review your information:\n");
        printf("1. Surname     : %s\n", surname_Name);
        printf("2. First Name  : %s\n", first_Name);
        printf("3. Middle Name : %s\n", middle_Name);
        printf("4. Age         : %d\n", age);
        printf("5. Email       : %s\n", email_User);
        printf("6. Address     : %s\n", location);
        printf("7. Contact     : %s\n", contactNum);
        printf("8. Continue and Save\n");
        printf("9. Exit without saving\n");
        printf("\n=================================\n");
        printf("Enter the number of the field you want to edit, or 8 to save, 9 to exit.");
    
        int editChoice;
            if (scanf("%d", &editChoice) != 1) {
                printf("Invalid input. Please enter a number.\n");
                continue;
        }
    
        if(editChoice == 8){ 
            break;
        } else if (editChoice == 9){
            printf("Exiting without saving.\n");
            return 0;
        }
    
        switch(editChoice){
            case 1:
                inputString("Enter your surname: ", surname_Name, sizeof(surname_Name), 1);
            case 2:
                inputString("Enter your first name: ", first_Name, sizeof(first_Name), 1);
                    break;
            case 3:
                inputString("Enter your middle name: ", middle_Name, sizeof(middle_Name), 1);
                    break;
            case 5:
                inputString("Enter your email: ", email_User, sizeof(email_User), 5);
                    break;
            case 6:
                inputString("Please type your address: ", location, sizeof(location), 1);
                    break;
            case 7:
                inputString("Contact Info: ex:(+63 0123 454 7327): ", contactNum, sizeof(contactNum), 5);
                    break;
            default:
                    printf("Invalid choice. Please select a number from 1 to 9.\n");
        }
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
