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

struct node * delet_between(struct node * head,int index)
{
    struct node * p_1 = head;
    struct node * p_2= head->next;
    int i = 0 ;
    while(i != index-1)
    {
        p_1 = p_1->next;
        p_2=p_2->next;
        i++;
    }
    p_1->next = p_2->next;
    
    free(p_2);
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
 fourth->next = NULL;

int index = 2;

 linked_list_traversal( head);
 
head = delet_between(head,index);

 linked_list_traversal( head);


 



 



}