//here we are learning stack using array ,for that we have first created a structure of stack which contain 
// size of stack ,index of top most element , and an array to store our stack 

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

int main()
{
    //here we have called our stack and filled there values 
 struct stack *s = ( struct stack *) malloc (sizeof(struct stack));;
 s->size = 80;
 s->top = -1;
 s->arr = (int *) malloc(s->size * sizeof(int));


if(is_empty(s))
{
    printf("stack is empty !!");
}
else if(is_full(s))
{
     printf("stack is full !!");
}
else
{
    printf("stack is not full nor empty !!!");
}

return 0;

 }