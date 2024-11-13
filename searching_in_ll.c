#include<stdio.h>

struct node{
    int data;
    struct node *next;
};


search(int item ,node *head){
    struct node *temp;
    temp =head;
    if(temp==NULL){
        printf("Empty list");
    }
    else{
        while(temp!=NULL){
            if(temp->info ==item){
                printf("Item found");
                break;
            }
            temp=temp->next;
        }
    }
}

