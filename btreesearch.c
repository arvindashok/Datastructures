#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newnode (int val){

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}
struct Node *CreateBranch (struct Node *root, int val)
{

    if (root == NULL)
    return newnode (val);

    else if (val > root->data)
    root->right = CreateBranch (root->right, val);

    else if (val < root->data)
    root->left = CreateBranch (root->left, val);

    return root;
}

void printlist (struct Node *tree){

    if (tree != NULL){
        printf ("%d\n",tree->data);
        printlist (tree->left);
        printlist (tree->right);
    }
}

struct Node *DeleteNode (struct Node *root, int key){
    if (root == NULL)
    return root; 

    if (key > root->data)
    root->right = DeleteNode (root->right, key);

    else if (key < root->data)
    root->left = DeleteNode (root->left, key);

    else{

        if (root->left == NULL && root->right == NULL)
        root == NULL;

        //else if (root->left == NULL && root->right != NULL)
        
    }
}

int searchtree (struct Node *findleaf, int key){
    
    if (key == findleaf->data)
    return 1;

    else if (key > findleaf->data)
    return (findleaf->right, key);

    else if (key < findleaf->data)
    return (findleaf->left, key);

    else
    return 0;
    
}


int main (){

    int a[10] = {16, 18, 10, 8, 24, 100, 20, 4, 14, 12}, i;
    struct Node *root = NULL;
    int search;

    for (i=0;i<10;i++)
    root = CreateBranch (root, a[i]);
    
    root = CreateBranch (root, 3);
    printlist (root);

    search = searchtree (root, 6);

    if (search == 0)
    printf ("\nUnseccesful search\n");

    else
    printf ("Element found\n");

    return 0;

}