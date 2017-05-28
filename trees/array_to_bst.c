//http://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

#include<stdio.h>
#include<stdlib.h>
 
/* A Binary Tree node */
struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;
};
 
struct TNode* newNode(int data);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct TNode* newNode(int data)
{
    struct TNode* node = (struct TNode*)
                         malloc(sizeof(struct TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

struct TNode * sortedArrayToBST( int arr[], int low, int high)
{

     if (low > high) return NULL;
     int mid = low + (high-low)/2;

     struct TNode *root = newNode(arr[mid]);

     root->left = sortedArrayToBST(arr, low, mid-1);
     root->right = sortedArrayToBST(arr, mid+1, high);

     return root;
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    struct TNode *root = sortedArrayToBST(arr, 0, n-1);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);

    printf("\n"); 
    return 0;
}
