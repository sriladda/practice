//http://www.geeksforgeeks.org/level-order-tree-traversal/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ptr {
   int data;
   struct node_ptr *left; 
   struct node_ptr *right; 
} node;

node * create_node(int data) {

    node * curr_node = malloc(sizeof (node));
    
    curr_node->data = data;
    curr_node->left = NULL;
    curr_node->right = NULL;
    
    return curr_node;
}

void bfs(node *root)
{
     if(root == NULL)
     {
         return;
     }
     enqueue(root->left);
     enqueue(root->right);
     printf("%d ", root->data);
     root = (node *) dequeue();
     bfs(root);
}

node *insert(node *root, int data) {
  
    if(root == NULL)
    {
       node * curr_node = create_node(data);
       root = curr_node;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

/* Driver program to test above functions*/
int main()
{
   /*            1
                / \
               /   \
              2     3
             / \
            /   \
           4     5
    */

    node *root = NULL;

    init_queue(sizeof(node));

    root = create_node(1);
    root->left        = create_node(2);
    root->right       = create_node(3);
    root->left->left  = create_node(4);
    root->left->right = create_node(5);
 
    printf("Expected: 1 2 3 4 5 \n");
    printf("Level Order traversal of binary tree is \n");
    bfs(root);
    printf("\n");
 
    return 0;
}
