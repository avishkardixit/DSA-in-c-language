//first we will create push pop functions and for that we need to make changes in stack using functions hence we will 
//call the stack using pointers not by simple call by name 

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;

};

// these is function which will chwck whether the stack is empty or not becouse when stack is empty 
// its index of top element will point on "-1" cauze index start from zero 
int is_empty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
         return 1;
    }
    else
    {
         return 0;
    }
}

//when the index of top element is equa to total size of stack then we can say that stack is full
int is_full(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
         return 1;
    }
    else
    {
         return 0;
    }
}

int push(int value, struct stack * ptr)
{
    if(is_full(ptr))
    {
        printf("stack is overflow !!!");
    }
    else
    {
       ptr->top++;
       ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    if(is_empty(ptr))
    {
        printf("stack is inerrflow !!!,, or stack had no element to pop");
    }
    else
    {  
       int val = ptr->arr[ptr->top];
       ptr->top = ptr->top-1;
       printf("%d\n",val);
       
       
    }
}

int peek(struct stack * ptr , int index)
{    int array_index = ptr->top - index + 1;
    if( array_index < 0)
    {
        printf("not valid position for stack !!!");
        return -1;
    }
    else
    {
        return ptr->arr[array_index];
    }
}

int main()
{
    //these structure pointer is creating dinamically memory using malloc
 struct stack *s =( struct stack *) malloc (sizeof(struct stack));
 s->size = 80;
 s->top = -1 ;
 s->arr = (int *) malloc(s->size * sizeof(int));
 push(34,s);
 push(60,s);
 push(67,s);
 push(98,s);
 push(994,s);

 for(int j = 1 ; j <=s->top + 1; j++)
 {
     printf("value at index %d is %d \n",j,peek(s,j));
 }








 }