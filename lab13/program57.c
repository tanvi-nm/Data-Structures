#include <stdio.h>

#define MAX 100
int TOP = -1;
int STACK[MAX];

void push(int value) {
    if (TOP >= MAX-1) {
        printf("Stack overflow!");
    }
    else {
        STACK[++TOP] = value;
    }
}

int pop() {
    if (TOP < 0) {
        printf("Stack underflow!");
        return -1;
    }
    else {
        return STACK[TOP--];
    }
}

int peek() {
    if (TOP >= 0 && TOP <= MAX-1) {
        return STACK[TOP];
    }
    else {
        printf("Invalid state of stack!");
        return -1;
    }
}

int peep(int index) {
    if (TOP - index + 1 < 0) {
        printf("Invalid index");
        return -1;
    }
    else {
        return STACK[TOP - index + 1];
    }
}

void change(int index, int value) {
    if (TOP - index + 1 < 0) {
        printf("Invalid index");
    }
    else {
        STACK[TOP - index + 1] = value;
    }
}

int main() {

    int choice = 1;

    while (choice) {
        printf("\n0 Exit\n");
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Peek\n");
        printf("4 Peep\n");
        printf("5 Change\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
        
        else if (choice == 1) {
            int value;
            printf("Enter value : ");
            scanf("%d", &value);
            push(value);
        }

        else if (choice == 2) {
            printf("%d", pop());
        }

        else if (choice == 3) {
            printf("%d", peek());
        }

        else if (choice == 4) {
            int index;
            printf("Enter index : ");
            scanf("%d", &index);
            printf("%d", peep(index));
        }

        else if (choice == 5) {
            int index;
            int value;
            printf("Enter index : ");
            scanf("%d", &index);
            printf("Enter value : ");
            scanf("%d", &value);
            change(index, value);
        }

        else {
            printf("Invalid choice entered!");
        }
    }
}