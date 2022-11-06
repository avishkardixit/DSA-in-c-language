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

struct node* insert_in_between(struct node * head , int data, int index)
{
    struct node* ptr = (struct node*) malloc (sizeof(struct node));//these is the address of new node

    struct node * p = head;//these is the node where we will insert new node 
    int i = 0;

    while(i != index - 1)//these loop will move our p from head to the element before the index by its condition
    {
        p = p->next; // now our p will point towards next element from index
        i++;
    }
    ptr->data = data; //set the data of new node
    ptr->next = p->next;//now our next of new node will be equal to next of p next meance next of the element before index
    p->next=ptr;//and the next of our elemnt before index will point towards ptr

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
 int index = 3;
 insert_in_between(head ,data,index);

linked_list_traversal( head);
}