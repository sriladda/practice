//http://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <stdio.h>

// C program to demonstrate delete operation in binary search tree
#include<stdio.h>
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
 
// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
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
 
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

// OKay, now work on meat of this program 
struct node * deleteNode(struct node *root, int data)
{
    if (!root)
    {
        return root;
    }

    if ( data < root->key)
    {
        root->left =  deleteNode(root->left, data);
        return root;
    }

    else if ( data > root->key)
    {
        root->right =  deleteNode(root->right, data);
        return root;
    }

    // Now that, root is not null, given key not < or > the root->key,
    // implies, we are at found the key position.
    else if ( data == root->key)
    {
        //printf("%s: root = %p, root->key = %d root->left = %p root->right = %p\n", __FUNCTION__, root, root->key, root->left, root->right);
        //case 1. the node to be deleted either has one child or no children
        // eg., 20 or 40
        //so the following 2 conditions work, for one or no children
        if (root->left == NULL) 
        {
            struct node * temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) 
        {
            struct node * temp = root->left;
            free(root);
            return temp;
        }
        // Now, handle the case when node to be deleted has both the children eg., 50 or 70
        // replace key to be deleted ie., root->key with min element on the right side like inorder successor.
        {
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            //printf(" data = %d temp->key = %d\n", data, temp->key);
            root->right = deleteNode(root->right,temp->key);
            return root;
        }
    }
    return root;
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
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\n");

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\n");
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\n");

    return 0;
}
