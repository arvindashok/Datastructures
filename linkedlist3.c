#include <stdio.h>
#include <stdlib.h>

struct Node{
    int rn;
    char *name;
    struct Node *next;
};

struct Node *push (int data, char *name2, struct Node *nodeN){

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->name = (char *)malloc(10*sizeof(char));

    newnode->name = name2;
    newnode->rn = data;
    newnode->next = nodeN;

    return newnode;
}
void delete(int key, struct Node *dNode){
    
    struct Node *temp=dNode, *next=NULL, *prev=NULL;
    
    while (temp!=NULL){
        prev=temp;
        next=temp->next;
        if (next->rn==key){
            prev->next=next->next;
            free (next);
            break;
        }
        temp=temp->next;
    } 
}

struct Node *add( int rn1, int data, char *name1, struct Node *pNode){
    
    struct Node *Node1=(struct Node *)malloc(sizeof(struct Node));
    Node1->name=(char *)malloc(10*sizeof(char));

    Node1->rn=data;
    Node1->name=name1;

    while (pNode!=NULL){
        if (pNode->rn==rn1){
            Node1->next=pNode->next;
            pNode->next=Node1;
            break;
        }
        pNode=pNode->next;
    }
    return pNode;

}

struct Node *reverse (struct Node *tNode){

    struct Node *first=NULL, *second=NULL, *third=NULL, *temp=tNode;

    while (temp!=NULL){
//temp is the moving pointer
        first=temp->next;//first points to the node to be reversed
        second=first->next;//second stores what first points to
        first->next=temp;//reversing the node
        temp->next=third;//reversing the parent to NULL in the first itteration and previous in later

        temp=second;//update temp to the stored node(second)
        third=first;//to save the previous node so link is not lost
    }
    return third;
}

struct Node * sort (struct Node *sNode){

    struct Node *temp=sNode, *first=NULL, *begin=sNode, *save=NULL;
    int k=0, swap;

    while (temp != NULL && temp->next != NULL){

        swap=0;
        first = temp->next;
       
        if (temp->rn > first->rn){
            swap+=1;
            temp->next = first->next;//swapping
            first->next = temp;//swapping

            if (k!=0)
            save->next = first;//linking the previous link to the list after swapping

            save = first;//saving the previous link

            if (k==0)
            begin=save;//saving the first link forever

            k++;
        }
        else if (swap==0 && temp->next != NULL){
            if(k==0)
            begin=temp;//if no swap for the first link

            save = temp;
            temp = temp->next;//if swap not required
            k++;
            
        }
    
    }  
    return begin;
}

void printlist (struct Node *p){

    while (p != NULL){
        printf ("%d %s\n", p->rn, p->name);
        p=p->next;
    }
}

struct Node *alloc(int data, char *name1){
    
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->name=(char *)malloc(10*sizeof(char));

    newNode->rn=data;
    newNode->name=name1;
    newNode->next=NULL;

    return newNode;
}

int main(){
    
    struct Node *newNode=NULL, *previous=NULL, *head=NULL;

    int n[6]={53, 27, 29, 7, 6, 28};
    char *p[6]={"Vikrant", "Aravind", "Aryan", "Adnan", "Aditya", "Arvind"};
    int i;

    for (i=0;i<6;i++){

        head = push(n[i],p[i],head);
        /*
        newNode = alloc (n[i], p[i]);
        if (i==0)
        head=previous=newNode;
        
        previous->next=newNode;
        previous=newNode;*/
        
    }
    //delete(7,head);
    //add(53,n[4],p[4],head);
    /*head = reverse (head);
    for (i=0; i<4; i++)
    head = sort (head);*/

    printlist (head);
    printf ("\n");

    return 0;
}