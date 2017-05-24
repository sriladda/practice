//http://www.geeksforgeeks.org/tree-traversals-preorder-preorder-and-postorder/

#include <stdio.h>
#include<stdlib.h>
 
struct node
{
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do preorder traversal of BST
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
 
// A utility function to do preorder traversal of BST
void preorder_iterative(struct node *root)
{
     while (1)
     {
         while (root)
         {
             printf("%d ", root->key);
             push(root);
             root = root->left;
         }
         if (is_stack_empty()) {
             break;
         }
         root = (struct node*) pop();
         root = root->right;
     }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    init_stack(sizeof(struct node)); 

    printf("Inorder traversal of the given tree \n");
    preorder(root);

    printf("Inorder traversal of the given tree using iterative approach\n");
    preorder_iterative(root);
 
    return 0;
}
