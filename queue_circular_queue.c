//in linear queue and circular queue the only difference is there increament style 
//in linear queue the positions are got increamented by one but in circular it will get 
//increamented by the formula by which when last element get increamented it will go to first
//position  element and hence it will becomes circular queue 

#include<stdio.h>
#include<stdlib.h>


struct  circular_queue
{
    int size;
    int f;//first element 
    int r;//last element 
    int * arr;
    
};

int is_full(struct circular_queue * q)
{
    if((q->r+1)%q->size == q->f)//it meanse when program will go trough all elements and last element will
                                //point on first 
    {
        return 1;
    }
    return 0;
}

int is_empty(struct circular_queue * q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    return 0;
}



//to add element in queue
void enqueue(struct circular_queue * q,int value)
{
    if(is_full(q))
    {
        printf("our queue is full !!!");
    }
    else
    {
        q->r = (q->r+1)%q->size;//formula to increament
        q->arr[q->r] = value;


    }
}

int dequeue(struct circular_queue * q)
{
    if( is_empty(q))
    {
        printf("the queue is empty !!!");
        return 0;
    }
    else
    {
        q->f = (q->f+1)%q->size;//formula to increament
        return q->arr[q->f];

    }
    
}

int main()
{
    struct circular_queue q;
    q.size = 4;
    q.r = q.f = 0;
    q.arr = (int *) malloc (q.size * sizeof(int));

    //enqueue some elements (adding)

    enqueue(&q,23);
    enqueue(&q,67);
    enqueue(&q,390);
    
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));

    enqueue(&q,45);
    enqueue(&q,45);
    enqueue(&q,45);

    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));
    printf("%d\n",dequeue(&q));


    
   
    
}






