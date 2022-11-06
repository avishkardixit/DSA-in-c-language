#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

void linked_list_traversal(struct node *ptr)
{
    while(ptr!= NULL)
    {
    printf("Element : %d \n",ptr->data);
    ptr = ptr->next;
    }
}

void linked_list_reverse_traversal(struct node *last_ptr)
{
    while(last_ptr != NULL)
    {
    printf("Element : %d ",last_ptr->data);
    last_ptr = last_ptr->prev;
    }
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
 head->prev = NULL;

 second->data = 32;
 second->next = third;
 second->prev = head;

 third->data = 55;
 third->next = fourth;
 third->prev = second;

 fourth->data = 75;
 fourth->next = NULL;
 fourth->prev = third;




 linked_list_traversal( head);
 linked_list_reverse_traversal(fourth);

}