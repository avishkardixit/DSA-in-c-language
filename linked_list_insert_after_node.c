#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void linked_list_traversal(struct node *ptr)
{
    while(ptr!= NULL)
    {
    printf("Element : %d ",ptr->data);
    ptr = ptr->next;
    }
    printf("\n");
}

struct node* insert_after_node(struct node *node ,int data)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));//these is the address of new node
//struct node *ptr;
ptr->data=data;
ptr->next=node->next;
node->next=ptr;



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
 fourth->next = NULL;



 linked_list_traversal( head);
 
 int data = 70;

 insert_after_node(second,data);

linked_list_traversal( head);
}