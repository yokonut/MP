#include "declaration.h"

void displayMainMenu() {

    printf("=====================================\n");
    printf("        Welcome to the Dictionary    \n");
    printf("=====================================\n");
    printf("1. Manage Data\n");
    printf("2. Language Tool\n");
    printf("3. Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

void manageDataMenu() {

    printf("=====================================\n");
    printf("          Manage Data Menu           \n");
    printf("=====================================\n");
    printf("1. Add Entry\n");
    printf("2. Add Translations\n");
    printf("3. Modify Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Delete Translation\n");
    printf("6. Display All Entries\n");
    printf("7. Search Word\n");
    printf("8. Search Translation\n");
    printf("9. Export\n");
    printf("10. Import\n");
    printf("11. Back to Main Menu\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

void languageToolMenu() {

    printf("=====================================\n");
    printf("          Language Tool Menu         \n");
    printf("=====================================\n");
    printf("1. Identify Main Language\n");
    printf("2. Simple Translation\n");
    printf("3. Back to Main Menu\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}


void displayEntry(Entry entry) {
    for (int i = 0; i < entry.count; i++) {
        printf("%d. Language: %s, Translation: %s\n", i + 1, entry.pairs[i].language, entry.pairs[i].translation);
    }
}
//check if entry already in dictionary
int findEntry(Entry dictionary[], int entryCount, char *language, char *translation, int foundIndices[]) {
    int foundCount = 0;
    for (int i = 0; i < entryCount; i++) {
        for (int j = 0; j < dictionary[i].count; j++) {
            if (strcmp(dictionary[i].pairs[j].language, language) == 0 && strcmp(dictionary[i].pairs[j].translation, translation) == 0) {
                foundIndices[foundCount++] = i;
                break;
            }
        }
    }
    return foundCount;
}

//add entry
void addEntry(Entry dictionary[], int *entryCount) {
  
    char language[MAX_LANG_LEN];
    char translation[MAX_TRANS_LEN];

    printf("Enter language: ");
    scanf("%s", language);
    printf("Enter translation: ");
    scanf("%s", translation);

    int foundIndices[MAX_ENTRIES];
    int foundCount = findEntry(dictionary, *entryCount, language, translation, foundIndices);

    if (foundCount > 0) {
        printf("Entry already exists:\n");
        for (int i = 0; i < foundCount; i++) {
            displayEntry(dictionary[foundIndices[i]]);
        }
        printf("Is this a new entry? (yes/no): ");
        char response[10];
        scanf("%s", response);
        if (strcmp(response, "no") == 0) {
            return;
        }
    }

    if (*entryCount < MAX_ENTRIES) {
        strcpy(dictionary[*entryCount].pairs[0].language, language);
        strcpy(dictionary[*entryCount].pairs[0].translation, translation);
        dictionary[*entryCount].count = 1;
        (*entryCount)++;
    } else {
        printf("Dictionary is full. Cannot add more entries.\n");
    }

    char addMore[10];
    do {
        printf("Do you want to add another language-translation pair? (yes/no): ");
        scanf("%s", addMore);
        if (strcmp(addMore, "yes") == 0) {
            if (dictionary[*entryCount - 1].count < MAX_PAIRS) {
                printf("Enter language: ");
                scanf("%s", language);
                printf("Enter translation: ");
                scanf("%s", translation);

                int lastEntryIndex = *entryCount - 1;
                strcpy(dictionary[lastEntryIndex].pairs[dictionary[lastEntryIndex].count].language, language);
                strcpy(dictionary[lastEntryIndex].pairs[dictionary[lastEntryIndex].count].translation, translation);
                dictionary[lastEntryIndex].count++;
            } else {
                printf("Entry already has maximum number of translation pairs.\n");
                break;
            }
        }
    } while (strcmp(addMore, "yes") == 0);
}
//add translation
void addTranslation(Entry dictionary[], int entryCount) {

    char language[MAX_LANG_LEN];
    char translation[MAX_TRANS_LEN];

    printf("Enter language of the existing entry: ");
    scanf("%s", language);
    printf("Enter translation of the existing entry: ");
    scanf("%s", translation);

    int foundIndices[MAX_ENTRIES];
    int foundCount = findEntry(dictionary, entryCount, language, translation, foundIndices);

    if (foundCount == 0) {
        printf("No entry found with the given language and translation pair. Please add the entry first.\n");
        return;
    }

    printf("Entries found:\n");
    for (int i = 0; i < foundCount; i++) {
        printf("Entry %d:\n", i + 1);
        displayEntry(dictionary[foundIndices[i]]);
    }

    int entryIndex;
    if (foundCount == 1) {
        entryIndex = foundIndices[0];
    } else {
        printf("Enter the number of the entry to add a translation to: ");
        scanf("%d", &entryIndex);
        entryIndex = foundIndices[entryIndex - 1];
    }

    char addMore[10];
    do {
        if (dictionary[entryIndex].count < MAX_PAIRS) {
            printf("Enter new language: ");
            scanf("%s", language);
            printf("Enter new translation: ");
            scanf("%s", translation);

            strcpy(dictionary[entryIndex].pairs[dictionary[entryIndex].count].language, language);
            strcpy(dictionary[entryIndex].pairs[dictionary[entryIndex].count].translation, translation);
            dictionary[entryIndex].count++;
        } else {
            printf("Entry already has maximum number of translation pairs.\n");
            break;
        }

        printf("Do you want to add another language-translation pair to the same entry? (yes/no): ");
        scanf("%s", addMore);
    } while (strcmp(addMore, "yes") == 0);
}


void manageData(Entry dictionary[], int *entryCount) {
    int manageChoice;
    do {
        manageDataMenu();
        scanf("%d", &manageChoice);
        switch (manageChoice) {
            case 1:
                addEntry(dictionary, entryCount);
                break;
            case 2:
                addTranslation(dictionary, *entryCount);
                break;
            case 3:
                // Implement Remove Entry functionality here
                break;
            case 4:
                // Implement View All Entries functionality here
                break;
            case 5:
                return; // Back to Main Menu
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (manageChoice != 5);
}