//first we will create push pop functions and for that we need to make changes in stack using functions hence we will 
//call the stack using pointers not by simple call by name 

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char * arr;

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

char push(char value, struct stack * ptr)
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

char pop(struct stack *ptr)
{
    if(is_empty(ptr))
    {
        printf("stack is inerrflow !!!,, or stack had no element to pop");
    }
    else
    {  
       char val = ptr->arr[ptr->top];
       ptr->top = ptr->top-1;
      return val;
       
       
    }
}
int bracket_match(char * exp)
{
    struct stack* sp;
    sp->size = 100;
    sp->top = -1 ;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    for(int i = 0 ; exp[i]!= '\0';i++)
    {
        if(exp[i] == '(')
        {
           push('(',sp);
        }
        else if (exp[i] == ')')
        {
           if(is_empty(sp))
           {
               return 0;
           }
           pop(sp);
        }
    }
    if(is_empty(sp))
    {
        return 1;
    }
    else
    {

    }
}

int main()
{

     char *exp = "8*((9))";
      if(bracket_match(exp))
      {
      printf(" the brackets are matching ");
      }
      else
      {
      printf(" the brackets are not matching ");
      }
      return 0;
      
}

