not working !!!!!

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
    q.size = 400;
    q.r = q.f = 0;
    q.arr = (int*) malloc(q.size * sizeof(int));

    //enqueue some elements (adding)

   
    
   //code of breadth first search graph
   int node;
   int i = 0;
   int visited[7] ={0,0,0,0,0,0,0};
   int a[7][7] = { 
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
        };
    printf("%d",i);
    visited[i] = 0;
    enqueue(&q,i);//enqueue i for exploration
    while(!is_empty(&q))
    {
       int node =dequeue(&q);
        for(int j = 0 ; j < 7 ;i++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d",j);
                visited[j] = 1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}






