//http://www.geeksforgeeks.org/stack-data-structure-introduction-program/

# include <stdio.h>
# include <stdlib.h>

#define N 20

void **stack;
int top = 0;

void init_stack(int element_size) {
    int i;

    stack = malloc(N * element_size);
    
    for(i = 0; i < N; i++)
    {
        stack[i] = malloc(element_size);
    }
}

//post increment
void push(void *data) 
{
    stack[top] = data;
    //printf("%s: stack[%d] = %d\n", __FUNCTION__, top, * (int *) stack[top] );
    top++;
}

//pre decrement
void * pop() 
{
    top--;
    //printf("%s: stack[%d] = %d\n", __FUNCTION__, top, * (int *) stack[top] );
    return stack[top];
}

int is_stack_empty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}

# if 0
int main()
{

    int arr[] = {10, 20, 30};
    int *ptr;

    init_stack(sizeof(int));

    push(&(arr[0]));
    push(&(arr[1]));
    push(&(arr[2]));
 
    ptr = (int *) pop();
    printf("%d popped from stack\n", *ptr);
 
    return 0;
}
#endif
