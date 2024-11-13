#include <stdio.h>
#include <stdlib.h>

// creating a doubly linked list

struct node {
    int data;
    struct node *prev;
    struct node *next;   
};

struct node* insertAtBeg(struct node* head, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next= head;
    temp->prev=NULL;
    if (head != NULL)
        head->prev = temp;
    head = temp;
    return head;
}

void printNode(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

struct node* insertAtEnd(struct node* head, int data) {
    struct node* temp = head;
    struct node* ptr4 = (struct node*)malloc(sizeof(struct node));
    ptr4->data = data;
    ptr4->next = NULL;

    if (head == NULL) {
        ptr4->prev = NULL;
        head = ptr4;
        return head;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = ptr4;
    ptr4->prev = temp;

    return head;
}

struct node* insertAtPosition(struct node* head, int data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return head;
    }

    struct node* temp = head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    if (temp->next == NULL) {
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Function to delete a node at the beginning
struct node* deleteAtBeg(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node at the end
struct node* deleteAtEnd(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node at a specific position
struct node* deleteAtPosition(struct node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (position == 1) {
        return deleteAtBeg(head);
    }

    struct node* temp = head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    return head;
}

// Function to reverse the list
struct node* reverseList(struct node* head) {
    struct node* temp = NULL;
    struct node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

int main(){
    struct node* head = NULL;

    head = insertAtBeg(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    printf("Original List:\n");
    printNode(head);

    head = reverseList(head);
    printf("Reversed List:\n");
    printNode(head);

    head = deleteAtPosition(head, 2);
    printf("List after deleting at position 2:\n");
    printNode(head);

    return 0;
}
