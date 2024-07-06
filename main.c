#include "function.c"

int main() {
    Entry dictionary[MAX_ENTRIES];
    int entryCount = 0;

    int choice = 0;
    while (choice != 3) {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageData(dictionary, &entryCount);
                break;
            case 2:
                languageToolMenu();
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}