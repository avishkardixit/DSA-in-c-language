#include<stdio.h>
#include<stdlib.h>
struct Node
{
     int data;
     struct Node * next;
};

    struct Node * r = NULL;//global variable to get access to change them from any function
    struct Node * f = NULL;

void print_queue(struct Node *ptr)
{
    printf("the elements in queue are :\n");
    while(ptr!= NULL)
    {
    printf("Element : %d \n",ptr->data);
    ptr = ptr->next;
    }
}

void enqueue(int value)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("queue is full");
    }
    else
    {
        n->data = value;
        n->next = NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else
        {
            r->next = n;
            r=n;
        }
    }
}



int dequeue()
{

    int val = -1;
    struct Node *ptr = f;
    if(f==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        f= f->next;
        val = ptr->data;
        free(ptr);

    }
}

int main()
{
  
    
    enqueue(34);
    enqueue(78);
    enqueue(390);
    enqueue(5);
    print_queue(f);
    dequeue();
     print_queue(f);
}