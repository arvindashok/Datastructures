#include <stdio.h>
#include <stdlib.h>

struct Node{
    int roll_number;
    char *name;
    struct Node *next;
};

struct Node *alloc(){
    struct Node *node= (struct Node*)malloc(sizeof(struct Node));
    return node;
}

void assign(struct Node *y){

        printf ("Enter roll number of the student:\n");
        scanf ("%d",&y->roll_number);
}

void printlist (struct Node *n){
    while (n){
        printf ("Roll number: %d\t\tName: %s\n",n->roll_number,n->name);
        n=n->next;
    }
}
int main(){
    
    struct Node *first;
    struct Node *second;
    struct Node *third;

    first=alloc();
    second=alloc();
    third=alloc();

    first->next=second;
    second->next=third;
    third->next=NULL;

    assign(first);
    assign(second);
    assign(third);

    first->name="Aravind";
    second->name="Arvind";
    third->name="Aryan";

    printlist (first);
    return 0;

}


