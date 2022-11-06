#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;

};
int push(int value, struct stack * ptr)
{
    ptr->top++;
    ptr->arr[ptr->top] = value;
    
}
int stack_top(struct stack *ptr)
{
   return ptr->arr[ptr->top];
}
int stack_bottom(struct stack *ptr)
{
     return ptr->arr[0];
}
int main()
{
    //these structure pointer is creating dinamically memory using malloc
 struct stack *s =( struct stack *) malloc (sizeof(struct stack));
 s->size = 80;
 s->top = -1 ;
 s->arr = (int *) malloc(s->size * sizeof(int));
 push(34,s);
 push(677,s);
 printf("top element of stack is %d \n",stack_top(s));
 printf("bottom element of stack is %d \n",stack_bottom(s));
}