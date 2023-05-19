#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = {0, NULL}; 

Node* creatNode(int value)
{
    Node* new_node;
    new_node = malloc(sizeof(Node*));
    new_node->data=value;
    new_node->next=NULL;

    return new_node;
}