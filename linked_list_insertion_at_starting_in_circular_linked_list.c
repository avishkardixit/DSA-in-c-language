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
// head->next and these head next will go to that position where the next of that position will pointing on head by while
// loop then p next will point on ptr and join our new ptr in list and then ptr next will point old head then our new ptr
// is now member of circular linked list and then new head will be our ptr by head = ptr;
struct node * insertion_at_start(struct node * head,int data)
{
  struct node * ptr = (struct node*)malloc(sizeof(struct node));
  ptr->data=89;
  struct node * p = head->next;
  
  while(p->next!=head)
  {
     p =  p->next;
  }
  p->next=ptr;
  ptr->next=head;
  head=ptr;
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
head = insertion_at_start(head,data);
linked_list_traversal( head);
}