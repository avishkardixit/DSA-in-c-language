#include<stdio.h>
#include<malloc.h>

//to create every node of tree
struct node{

    int data;
    struct node * left;
    struct node * right;

};
typedef struct node * NODEPTR;  //give short name to struct node *

NODEPTR create_node(int data)
{     NODEPTR n;
      n=(NODEPTR)malloc(sizeof(struct node ));
      n->data=data;
      n->left = NULL;
      n->right = NULL;
      return n;
}



int main()
{   //creating nodes  
     NODEPTR p = create_node(56);
     NODEPTR p1 = create_node(33);
     NODEPTR p2 = create_node(67);

     //link the nodes 
     p->left=p1;
     p->right=p2;

     //print the data 
     printf("%d %d %d ",p->data,p1->data,p2->data);
     
}