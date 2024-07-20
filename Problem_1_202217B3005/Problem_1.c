#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int list[MAX], n = 0;

int main() {
    int choice;
    char continue_choice = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1.Create");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Insert");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter the correct choice:\n");
        }

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y');

    return 0;
}

void create() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of elements exceeds the maximum limit of %d\n", MAX);
        n = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &list[i]);
    }
}

void insert() {
    int pos, element;

    if (n >= MAX) {
        printf("List is full\n");
        return;
    }

    printf("Enter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos > n || pos < 0) {
        printf("Invalid position\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    for (int i = n; i > pos; i--) {
        list[i] = list[i - 1];
    }

    list[pos] = element;
    n++;

    printf("Element inserted successfully\n");
}

void deletion() {
    int pos;

    if (n == 0) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("Invalid position\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        list[i] = list[i + 1];
    }

    n--;

    printf("Element deleted successfully\n");
}

void search() {
    int element, found = 0;

    if (n == 0) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for (int i = 0; i < n; i++) {
        if (list[i] == element) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found in the list\n");
    }
}

void display() {
    if (n == 0) {
        printf("List is empty\n");
        return;
    }

    printf("Elements in the list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}