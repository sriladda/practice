//http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

#include<stdio.h>
#include<stdlib.h>
 
 
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) 
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
   
    return(node);
}

int max(int a, int b)
{
    return (a>b?a:b);
}

int maxDepth(struct node * root)
{
    if (root == NULL) return 0;
    return max( maxDepth(root->left), maxDepth(root->right) ) + 1;
}
   
int main()
{
    struct node *root = newNode(1);
 
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5); 
   
    printf("Hight of tree is %d", maxDepth(root));
   
    getchar();
    return 0;
}
