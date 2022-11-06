#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void linked_list_traversal(struct node *head)
{
    struct node * ptr = head;

    //these do while lopp will first print the head element and then it will print next elments until ptr will be head
    
    printf("elements :");
    do{
        
    printf(" %d ",ptr->data);
    ptr = ptr->next;
    
    }while(ptr != head);
    printf("\n");
}

//these function first creat new ptr and store data value in it then creat another node p which will point towards 
// head and these p will go to that position where the next of that position will pointing on index by while
// loop then p next will point on ptr and join our new ptr in list and then ptr next will point old head then our new ptr
// is now member of circular linked list and then new head will be our ptr by head = ptr;
struct node * insertion_at_between(struct node * head,int data,int index)
{
  struct node * ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data=data;
  struct node * p = head;
  
  for(int i = 0 ; i < index-1 ; i++)
  {
     p = p->next;
    
  }
  ptr->next=p->next;
  p->next=ptr;
  
 
 
  return head;


}

int main()
{
 //here we initiated the three pointer variables which are abel to store address of struct

 struct node * head;
 struct node * second;
 struct node * third;
 struct node * fourth;

//these will dinamically create storage  by malloc in heap storage

 head = (struct node*) malloc (sizeof(struct node));
 second = (struct node*) malloc (sizeof(struct node));
 third = (struct node*) malloc (sizeof(struct node));
 fourth = (struct node*) malloc (sizeof(struct node));

 //now we will add values and link the list with each other

 head->data = 40;
 head->next = second;       //these will add the address of second node in first node

 second->data = 32;
 second->next = third;

 third->data = 55;
 third->next = fourth;

 fourth->data = 75;
 fourth->next = head;



 linked_list_traversal( head);

int data = 89;
int index = 2;
head = insertion_at_between(head,data,index);
linked_list_traversal( head);
}