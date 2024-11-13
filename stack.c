#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } 
    else {
        struct Node* temp = top;
        printf("%d popped from stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } 
    else {
        struct Node* temp = top;
        printf("Stack elements are: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();
    return 0;
}