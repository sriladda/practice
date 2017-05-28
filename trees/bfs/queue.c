//Implement queue as needed for BFS
//http://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

#include <stdio.h>
#include <stdlib.h>

#define N 20

void** queue;// arr of pointers
int enqueue_point = -1, dequeue_point = -1, size = -1;

int is_empty()
{
    if (enqueue_point == -1) {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int is_full()
{
    if (dequeue_point == N) {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//pre-increment queue index
void enqueue(void* data)
{
    size++;
    if(is_full()) 
    {
        printf("%s: Queue is full\n", __FUNCTION__);
	return;
    }
    enqueue_point++;
    //printf("%s: enqueue_point = %d\n", __FUNCTION__, enqueue_point);
    queue[enqueue_point] = data;
}

int queue_size() 
{
    return size;
}

//post-decrement queue index
void* dequeue()
{
    size--;
    if(is_empty())
    {
        printf("%s: Queue is empty\n", __FUNCTION__);
	return NULL;
    }
    dequeue_point++;
    return queue[dequeue_point];
}

void init_queue(int pointer_size ) //size is size of each element in the queue
{
    int i;

    queue = malloc(pointer_size * N);
    for(i = 0; i <N; i++)
    {
        queue[i] = malloc(sizeof (pointer_size));
    }
}

#if 0
// Driver program to test above functions./
int main()
{
    float arr[] = {10, 20, 30, 40};
    float data;

    //int arr[] = {10, 20, 30, 40};
    //int data;

    init_queue(sizeof(arr[0])); //here int is our element in the queue.

    enqueue(&arr[0]);
    enqueue(&arr[1]);
    enqueue(&arr[2]);
    enqueue(&arr[3]);
    
    data = * ((float *) dequeue());
    printf("%f dequeued from queue\n", data);
 
    data = * ((float *) dequeue());
    printf("%f dequeued from queue\n", data);
 
    data = * ((float *) dequeue());
    printf("%f dequeued from queue\n", data);
 
    data = * ((float *) dequeue());
    printf("%f dequeued from queue\n", data);
 
    data = * ((float *) dequeue());
    printf("%f dequeued from queue\n", data);
 
    data = * ((float *) dequeue());
    printf("%f dequeued from queue\n", data);
 
    return 0;
}
#endif
