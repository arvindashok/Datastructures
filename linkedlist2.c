#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *New(int num,struct Node *newnode){

    struct Node *node=(struct Node*)malloc(sizeof(struct Node));
    node->data=num;
    node->next=newnode;

    return node;
}

struct Node *Construct(){
    struct Node *node= New(100,New(101,New(102,New(103,NULL))));
    return node;
}

void printlist(struct Node *node){
    struct Node *p=node;
    while (p!=NULL){
        printf ("%d\n",p->data);
        p=p->next;
    }
}


int main(){

    struct Node *head=Construct();
    printlist(head);
    
    return 0;
}