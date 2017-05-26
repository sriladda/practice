//http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
// C program for iterative postorder traversal using one stack

#include <stdio.h>
#include <stdlib.h>
 
// A tree node
struct node
{
    int key;
    struct node *left, *right;
};

// Stack type
struct Stack
{
    int size;
    int top;
    struct node* *array;
};
 
// A utility function to create a new tree node
struct node* newNode(int data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key = data;
    node->left = node->right = NULL;
    return node;
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

// A utility function to do inorder traversal of BST
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct node**) malloc(stack->size * sizeof(struct node*));
    return stack;
}

// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{  return stack->top == -1; }
 
void push(struct Stack* stack, struct node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
struct node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
} 

void postorder_iterative(struct node *root)
{
    struct Stack *stack1 = createStack(20);
    struct Stack *stack2 = createStack(20);

    push(stack1, root);

    while(!isEmpty(stack1))
    {
        struct node * temp = pop(stack1);

        if (temp)
        {
            push(stack1, temp->left);
            push(stack1, temp->right);
        }
         
        push(stack2, temp);
        temp = peek(stack2);
    }
    while(!isEmpty(stack2))
    {
        struct node * temp = pop(stack2);

        if (temp)
            printf("%d ", temp->key);
    }

}

#if 0
// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              50
           /     \
          40      60
         /  \    /  \
       20   30  70   80 */
    struct node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);

    //init_stack(sizeof(struct node)); 
    printf("Postorder traversal of the given tree \n");
    postorder(root);
 
    printf("Postorder traversal using iterative approach\n");
    postorder_iterative(root);
 
    return 0;
}
#endif

/* Driver program to test above functions*/
int main()
{
     struct node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5); 
 
     printf("\nPostorder traversal of binary tree is \n");
     postorder(root);
 
     printf("\nPostorder traversal using iterative approach\n");
     postorder_iterative(root);
 
     getchar();
     return 0;
}
