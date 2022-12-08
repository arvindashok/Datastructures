#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int stack [SIZE];
int top = -1;

int isFull (){
    if (top==SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty (){
    if (top<0)
        return 1;
    else
        return 0;
}
void push (int x){

    if (isFull()){
        printf ("Stack is full!\n");
    }
    else{
            stack [++top]=x;
    }
}
void pop (){

    if (isEmpty()){
        printf ("Stack is empty\n");
    }
    else{
        stack [top--]=0;
    }
}
void print (){

    printf ("Elements are:\n");
    for (int i=0; i<=top; i++){
        printf ("%d\t",stack[i]);
    }
}
void input (int *a){

    printf ("Enter the elements:\n");
    scanf ("%d",&a);
    push (a);

}
int main()
{
    int a;
    int user_input;

    while (1){
        printf ("\n1:Push\n2:Pop\n3.Display\n4.Quit\n");
        scanf ("%d",&user_input);

        switch (user_input){

            case 1: input (&a);
            break;

            case 2: pop ();
            break;

            case 3: print ();
            break;

            case 4: exit (0);
            break;
         }
    }

    return 0;
}