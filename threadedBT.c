#include <stdio.h> 
#include <stdlib.h> 
struct node{
    int data; struct Node *left, *right;
    int isThreaded; };

struct node* createnode(int data){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    newnode->isThreaded=0;
    return newnode;
}

struct node* insert(struct node* root,int data){
    
}