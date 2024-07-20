#include <stdio.h>
#include <stdlib.h> // For exit()

#define MAX 5

void main() {
    int queue[MAX], ch = 1, front = 0, rear = 0, i;
    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");

    while (ch) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: // Insertion
                if (rear == MAX) {
                    printf("\nQueue is Full");
                } else {
                    int value;
                    printf("\nEnter value to insert: ");
                    scanf("%d", &value);
                    queue[rear++] = value;
                }
                break;
                
            case 2: // Deletion
                if (front == rear) {
                    printf("\nQueue is Empty");
                } else {
                    printf("\nDeleted Element is %d", queue[front++]);
                }
                break;

            case 3: // Display
                printf("\nQueue Elements are:\n");
                if (front == rear) {
                    printf("\nQueue is Empty");
                } else {
                    for (i = front; i < rear; i++) {
                        printf("%d\n", queue[i]);
                    }
                }
                break;

            case 4: // Exit
                exit(0);
                break;

            default:
                printf("Wrong Choice: Please see the options");
        }
    }
}