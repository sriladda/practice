//http://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/

/*
*
  Inorder Successor
  =================
  There are two cases for the node.
  1) if the node has right child. Then the successor would be the leftmost node (or mininum) of its right subtree.
  2) if the node has no right child. Then the successor would be the lowest node whose left subtree contains the node.
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right ;
}Node;

// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp =  malloc(sizeof (Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

Node *find(Node *root, int key)
{
    if(!root)  return NULL;
    if(root->key == key)  return root;
    else if(key < root->key) find(root->left, key);
    else find(root->right, key);
}

Node *find_min(Node *root)
{
    Node *curr = root;
    if(!root)  return NULL;

    while(curr->left) 
    {
        curr=curr->left;
    }
    return curr;
}

Node *find_max(Node *root)
{
    Node *curr = root;
    if(!root) return NULL;

    while(curr->right) 
    {
        curr=curr->right;
    }
    return curr;
}

Node * successor(Node *root, int key)
{
    Node *curr = find(root,key);
    if(!curr) return NULL; // ie., no node with given key.
    if (curr->right) 
    {
        return find_min(curr->right);
    }
    //Handle the case, there is no right subtree to given search key
    //start at root
    {
        Node * ancestor = root;
        Node * successor = NULL;
        while(curr != ancestor) 
        {
            if (curr->key < ancestor->key) 
            {
                 successor = ancestor;
                 ancestor = ancestor->left;
            }
            else
            {
                 ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

Node * predecessor(Node *root, int key)
{
    Node *curr = find(root,key);
    if(!curr) return NULL; // ie., no node with given key.
    if (curr->left) 
    {
        return find_max(curr->left);
    }
    //Handle the case, there is no left subtree to given search key
    //start at root
    {
        Node * ancestor = root;
        Node * predecessor = NULL;
        while(curr != ancestor) 
        {
            if (curr->key > ancestor->key) 
            {
                 predecessor = ancestor;
                 ancestor    = ancestor->right;
            }
            else
            {
                 ancestor = ancestor->left;
            }
        }
        return predecessor;
    }
}

// Driver program to test above function
int main()
{
    //int key = 30;    //Key to be searched in BST
    int key = 70;    //Key to be searched in BST
    //int key = 50;    //Key to be searched in BST
    //int key = 65;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

   /* Let us create following BST
              50
           /      \
          30       70
         /          \
       20           80 */

    Node *root = NULL;
    Node* pre = NULL, *suc = NULL;

    root = insert(root, 50);

    insert(root, 30);
    insert(root, 20);
    //insert(root, 40);
    insert(root, 70);
    //insert(root, 60);
    insert(root, 80);

    suc = successor(root, key);
    if (suc) 
        printf("Successor is %d\n", suc->key);
    else
        printf("NO Successor\n");

    pre = predecessor(root, key);
    if (pre) 
        printf("Predecessor is %d\n", pre->key);
    else
        printf("NO Predecessor\n");

    return 0;
}
