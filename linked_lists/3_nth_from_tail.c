//http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
// Simple C program to find n'th node from end
 #include<stdio.h>
 #include<stdlib.h>
  
/* Link list node */
struct Node
{
  int data;
  struct Node* next;
};

void printNthFromLast(struct Node *head, int n)
{
  int len, count;
  struct Node *temp;

  for(temp = head, len = 0; temp; temp = temp->next) len++;
  printf("len = %d n = %d\n", len, n);
  if (len < n) return;
  for(temp = head, count = 1; count < len-n+1; temp = temp->next)
  {
     //printf("temp->data = %d\n", temp->data);
     count++;
  }
  printf("temp->data = %d\n", temp->data);
}

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
 
/* Drier program to test above function*/
int main()
{
  /* Start with the empty list */
  struct Node* head = NULL;
 
  //create linked 35->15->4->20
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 35);
  
 printNthFromLast(head,4 );
 printNthFromLast(head,3 );
 printNthFromLast(head,2 );
 printNthFromLast(head,1 );
 return 0; 
}
