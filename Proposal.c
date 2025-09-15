#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
int main(){
    FILE *fptr;
    bool isStudent = true;
    char name[50] = "";
    char location[50] = "";
    int age = 0;
    int choice;

    printf("Create a Student Account... \n");
    printf("Create a Student Account... \n");
    printf("1. Continue\n");
    printf("2. Exit\n");
    printf("\nEnter your choice: ");
    scanf(" %d", &choice);
    getchar(); 
    switch(choice){
        case 1:
            printf("Enter your name: ");
            fgets(name, sizeof(name), stdin);
            if (name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';
            while(strlen(name) < 10){
                printf("(It must have 10+ characters)\n"); 
                printf("Enter your full name: ");
                fgets(name, sizeof(name), stdin);
                if (name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';
            }
            printf("Enter your age: ");
            scanf("%d", &age);
            getchar(); 
            if (age<=17){
                printf("You must consult with your parents to use this feature... Continue if present\n");
                return 1;
            }
            printf("Please type your address: ");
            fgets(location, sizeof(location), stdin);
            if (location[strlen(location) - 1] == '\n') location[strlen(location) - 1] = '\0';
            break;
        case 2:
            printf("You have successfully exited.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    printf("=================================\n");
    printf("%s\n", name);
    printf("%d\n", age);
    printf("%s\n", location);
    
    fptr = fopen("C:/Users/ACER/Desktop/userdata.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    

    fprintf(fptr, "Name     : %s\nAge     : %d\nLocation     : %s", name, age, location);
    
    fclose(fptr);
    printf("Text has been saved to userdata.txt\n");
    return 0;
}