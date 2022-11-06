#include<stdio.h>
#include<stdlib.h>


struct queue
{
    int size;
    int f;//first element 
    int r;//last element 
    int * arr;
    
};

int is_full(struct queue * q)
{
    if(q->r == q-> size-1)
    {
        return 1;
    }
    return 0;
}

int is_empty(struct queue * q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    return 0;
}



//to add element in queue
void enqueue(struct queue * q,int value)
{
    if(is_full(q))
    {
        printf("our queue is full !!!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;


    }
}

int dequeue(struct queue * q)
{
    if( is_empty(q))
    {
        printf("the queue is empty !!!");
    }
    else
    {
        q->f++;
        return q->arr[q->f];

    }
    
}

int main()
{
    struct queue q;
    q.size = 100;
    q.r = q.f = -1;
    q.arr = (int *) malloc (q.size * sizeof(int));

    //enqueue some elements (adding)

    enqueue(&q,23);
    enqueue(&q,67);
    enqueue(&q,390);
    
    printf("%d",dequeue(&q));
     printf("%d",dequeue(&q));
     printf("%d",dequeue(&q));

    
   
    
}






