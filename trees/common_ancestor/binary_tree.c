//http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
//https://www.youtube.com/watch?v=TIoCCStdiFo#t=10.485291


/**********
 This method assumes that both the keys are present.
**********/ 

// Driver program to test above functions


/* Program to find LCA of n1 and n2 using one traversal of Binary Tree.
   It handles all cases even when n1 or n2 is not there in Binary Tree */
#include <stdio.h>
#include <stdlib.h>

// A Binary Tree Node
typedef struct node
{
    struct node *left, *right;
    int key;
}Node;
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = malloc(sizeof(Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node * findLCA(Node *root, int n1, int n2)
{
    if (root == NULL) return NULL;
    if(root->key == n1 || root->key == n2) return root;

    Node *left = findLCA(root->left, n1, n2);
    Node *right = findLCA(root->right, n1, n2);

    if (left && right) return root; // left and right are found under this root,so this is your lca

    // you come here if only one of these is true, so return the true one
    if (left != NULL)
        return left;
    else
        return right;
}

void  preorder(Node *root)
{
    if(root)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    Node *lca;

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    preorder(root);
    lca =  findLCA(root, 4, 5);
    if (lca != NULL)
       printf("LCA(4, 5) = %d\n", lca->key);
    else
       printf("Keys 4 and 5 are not present\n");
 
    lca =  findLCA(root, 4, 10);
    if (lca != NULL)
       printf("LCA(4, 10) = %d\n", lca->key);
    else
       printf("Keys 4 and 10 are not present\n ");
 
    return 0;
}
