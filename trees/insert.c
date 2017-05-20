//http://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ptr {
   int data;
   struct node_ptr *left; 
   struct node_ptr *right; 
} node;

node * create_node(data) {

    node * curr_node = malloc(sizeof (node));
    
    curr_node->data = data;
    curr_node->left = NULL;
    curr_node->right = NULL;
    
    return curr_node;
}

void inorder(node *root)
{

    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
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

int main()
{
    node *root = NULL;

//# if 0

   //################### Test 1 ######################################//
   /*        49
           /     \
          46      79
         /
       41                */

    root = insert(root, 49);
    insert(root, 79);
    insert(root, 46);
    insert(root, 41);

    printf("Expected inorder is: 41 46 49 79\n");
    printf("Printing the tree elements in Preorder:\n"); 
    inorder(root);
    printf("\n");
//#endif 

//# if 0

   //################### Test 2 ######################################//
     /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    //Starting with new test case, so make root = NULL so that start fresh

    root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Expected inorder is: 20  30  40  50  60  70  80\n");
    // print inoder traversal of the BST
    inorder(root);
    printf("\n");
//#endif  

}
