#include<stdio.h>
#include<stdlib.h>

struct Node{
    int rn;
    char *name;
    struct Node *next;
};

struct Node *push(struct Node *headref, int data, char *names){
    
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->name = (char *)malloc(10*sizeof(char));

    newnode->rn = data;
    newnode->name = names;
    newnode->next = headref;
    
    return newnode;
}

void printlist (struct Node *i){

    while (i != NULL){
        printf ("%d\t%s\n", i->rn, i->name);
        i=i->next;
    }
}

void splitlist (struct Node *start, struct Node *front, struct Node *back){

    struct Node *slow, *fast;
    slow = start;
    fast = start->next;

    while (fast != NULL){

        fast = fast->next;

        if (fast != NULL){
            slow = slow->next;
            fast = fast->next; 
        }//fast moves twice, slow moves once
        //halves the linked list

    }
    front = start;//first half
    back = slow->next;//first half
    slow->next = NULL;//disconnecting second half from first half
}

struct Node *merging (struct Node *a, struct Node *b){

    struct Node *result = NULL;

    if (a==NULL)
    return b;

    if (b==NULL)
    return a;

    if (a->rn <= b->rn){
        result = a;
        result->next = merging (a->next ,b);
    }
    else{
        result = b;
        result->next = merging (a, b->next);
    }
    return result;
}

void mergesort (struct Node *formal){

    struct Node *head = formal;
    struct Node *a, *b;

    if (head == NULL || head->next == NULL) return;

    splitlist (head, a, b);//splitting list into 2 halves

    mergesort (a);
    mergesort (b);//splitting the two halves using recurrsion

    formal = merging (a, b);
    
}

int main (){

    struct Node *head = NULL;
    int n[6]={53, 27, 29, 57, 6, 28};
    char *p[6]={"Vikrant", "Aravind", "Aryan", "Dhruva", "Aditya", "Arvind"};
    int i;

    for (i=5;i>=0;i--)
    head = push (head, n[i], p[i]);

    mergesort (head);
    printlist (head);

    return 0;

    
}