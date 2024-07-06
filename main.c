#include "declaration.h"

int main(){

int choice = 0;
    while (choice != 3) {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageData();
                int manageChoice;
                scanf("%d", &manageChoice);
                if (manageChoice == 4) continue; // Back to Main Menu
                // Handle Manage Data options here
                break;
            case 2:
                languageTool();
                int toolChoice;
                scanf("%d", &toolChoice);
                if (toolChoice == 3) continue; // Back to Main Menu
                // Handle Language Tool options here
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

}