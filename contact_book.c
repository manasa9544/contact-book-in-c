#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact {
    char name[50];
    char phone[15];
};

void addContact() {
    struct Contact c;
    FILE *fp = fopen("contacts.txt", "a");
    printf("Enter Name: ");
    scanf("%s", c.name);
    printf("Enter Phone: ");
    scanf("%s", c.phone);
    fprintf(fp, "%s %s\n", c.name, c.phone);
    fclose(fp);
    printf("Contact Saved!\n");
}

void showContacts() {
    struct Contact c;
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) { printf("No contacts yet!\n"); return; }
    printf("\n--- All Contacts ---\n");
    while (fscanf(fp, "%s %s", c.name, c.phone) != EOF) {
        printf("Name: %s | Phone: %s\n", c.name, c.phone);
    }
    fclose(fp);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Contact\n2. Show Contacts\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 1) addContact();
        else if(choice == 2) showContacts();
        else if(choice == 3) break;
        else printf("Wrong choice!\n");
    }
    return 0;
}
