//http://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
/* C Program to remove duplicates from a sorted linked list */
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node *node);

void removeDuplicates(struct Node * head)
{
   struct Node *temp, *prev = head, *curr;

   for(; prev; )
   {
       curr = prev->next;
       if (curr)
           printf("prev = %p prev->data = %d curr = %p curr->data = %d\n", prev, prev->data, curr, curr->data);
       if( curr)
       {
           if (curr->data == prev->data)
           {
               prev->next = curr->next;
               temp = curr;
               curr = curr->next;
               free(temp);
           }
           //if data is different, change both prev and curr
           else
           {
               prev = prev->next;
               curr = curr->next;
           }
       }
       else
       {
           prev = prev->next;
       }
   }
   //printList(head);
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
             
    /* put in the data  */
    new_node->data  = new_data;
                 
    /* link the old list off the new node */
    new_node->next = (*head_ref);     
         
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }
}  

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
   
    /* Let us create a sorted linked list to test the functions
 *      Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);  
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                    
 
    printf("\n Linked list before duplicate removal  ");
    printList(head); 
 
    /* Remove duplicates from linked list */
    removeDuplicates(head); 
 
    printf("\n Linked list after duplicate removal ");         
    printList(head);            
   
    return 0;
}
