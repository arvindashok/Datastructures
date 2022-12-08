#include <stdio.h>
#include <stdlib.h>

struct Node{
    int rn;
    char *names;
    struct Node *next;
    struct Node *prev;
};

struct Node *push (struct Node *node, int data, char *name){

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->names = (char *)malloc(10*sizeof(char));

    newnode->rn = data;
    newnode->names = name;

    newnode->next = node;

    if (node == NULL)
    newnode->prev = NULL;

    else 
    newnode->prev = node;

    return newnode;
}

struct Node *reverse (struct Node *node){

    struct Node *rev_node = NULL, *temp =  NULL, *start = NULL;
    int k=0;

    while (node->next != NULL){
        node = node->next;
    }

    while (rev_node->prev != NULL){

    rev_node = node;
    temp = rev_node->prev;
    rev_node->prev = rev_node->next;
    rev_node->next = temp;

    if (k==0)
    start=rev_node;

    rev_node = rev_node->next; 
    k++;

    }
    return rev_node;
}

void printlist (struct Node *p){
    while (p!=NULL){
        printf ("Roll number:%d\tName:%s\n",p->rn, p->names);
        p=p->next;
    }
}

int main (){

    struct Node *head = NULL;
    int n[6]={53, 27, 29, 21, 6, 28}, i;
    char *p[6]={"Vikrant", "Aravind", "Aryan", "Anoshor", "Aditya", "Arvind"};
    
    for (i=0; i<6; i++){
        head = push (head, n[i], p[i]);
    }
    head = reverse (head);
    printlist (head);

    return 0;
}