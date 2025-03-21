#include <stdio.h>

#define MAX 100

int stack[MAX], choice, n, top = -1, x, i;

// Function declarations
void push(void);
void pop(void);
void display(void);

int main() {
    printf("\n Enter the size of STACK[MAX=%d]:", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("Stack size cannot exceed %d\n", MAX);
        return 1;
    }
    
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    do {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT ");
                break;
            default:
                printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top >= n - 1) {
        printf("\n\t STACK is overflow");
    } else {
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void pop() {
    if (top <= -1) {
        printf("\n\t Stack is underflow");
    } else {
        printf("\n\t The popped element is %d", stack[top--]);
    }
}

void display() {
    if (top >= 0) {
        printf("\n The elements in STACK are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
        printf("\n Press Next Choice");
    } else {
        printf("\n The STACK is empty");
    }
}
