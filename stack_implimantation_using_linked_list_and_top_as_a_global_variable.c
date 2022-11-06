//here we are making stack using linked list 


#include<stdio.h>
#include<stdlib.h>

//these is the structure wich create our linked list
struct node
{
    int data;
    struct node * next;

};

struct node * top=NULL; //here top is now globel variable now it can be changed from any function

//these function will check the stack we have created using linked list is empty or not 
//when the top of our stack is NULL then our stack is empty 
int is_empty(struct node * top )
{
 if(top == NULL)
 {
     return 1;
 }
 else
 {
     return 0;
 }
}

//it will check that the stack is full or not by allocating memory dinamically for pointer 
//if the pointer is allocated succefully then stack is not full but if not then it return null and hence we 
//will know stack is full
int is_full(struct node * top)
{
  struct node * p = (struct node *)malloc(sizeof(struct node *));
  if(p == NULL)
  {
      return 1;
  }
  else 
  {
      return 0;
  }
}
//these function will push the element in our stack by simply a method of insertion at first which 
//we have already studied in linked list insertion 
struct node * push(struct node * top , int value)
{
    if(is_full(top))
    {
        printf("stack is overflow !!\n");
    }
    else
    {
        struct node * n = (struct node *) malloc(sizeof(struct node));
        n->data = value;
        n->next = top;
        top = n;
       return top;
    }
}

int pop(struct node * top2 )
{
    if(is_empty(top2))
    {
        printf("stack is inerrflow !!!");
    }
    else
    {
        struct node * n = top2;
        top=top2->next;
        int x = n->data;
        free(n);
        return x;

    }
}

void linked_list_traversal(struct node *ptr)
{
    while(ptr!= NULL)
    {
    printf("Element : %d \n",ptr->data);
    ptr = ptr->next;
    }
}

int main()
{
  
    top= push(top,78);
    top = push(top,7);
    top = push(top,8);
    top = push(top,780);

    int poped_element = pop(top);
    printf("poped element is %d ",poped_element);
    int poped_element2 = pop(top);
    printf("poped element is %d ",poped_element2);
    
}