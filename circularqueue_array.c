#include <stdio.h>
#include <stdlib.h>

#define SIZE 3


int queue [SIZE];
int front=-1, rear=-1;

int isFull (){

    if (rear==SIZE-1 && front==0)
        return 1;
    else
        return 0;
}

int isEmpty (){

    if (front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

void enqueue (int *x){

    if (isFull())
        printf ("Queue overflow!\n");

    else if (isEmpty()){
        front=0;
        queue[++rear]=*x;
    }
    else{
        rear=(rear+1)%SIZE;
        queue[rear]=*x;
    }
}

void dequeue (){

    if (isEmpty())
        printf ("Queue underflow!\n");

    else if (front>=rear){
        queue[front]==0;
        front=-1;
        rear=-1;
    }
    else
        queue[front++]=0;
}

void display (){

        for (int i=front; i!=rear; (i+1)%SIZE)
            printf ("%d\t", queue[i]);
}

int main()
{
    int choice, input;
    
    while (1){
        printf ("\n1:Enqueue\n2:Dequeue\n3:Display\n4:Quit\n");
        scanf ("%d",&choice);

        switch (choice){

            case 1:printf ("Enter element to be added:\n");
            scanf ("%d", &input);
            enqueue (&input);
            break;

            case 2:dequeue();
            break;

            case 3:display();
            break;

            case 4:exit (0);
            break;

            default:printf ("Enter a valid choice!\n");
            break;
        }
    }

    return 0;
}