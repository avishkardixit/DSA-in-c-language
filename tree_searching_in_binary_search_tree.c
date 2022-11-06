
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
};
struct node * create_node(int data )
{
    struct node *n ;
    n = (struct node *) malloc(sizeof(struct node));
    n->data= data ;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node * search(struct node * root , int value )
{
    if(root == NULL)
    {
        return NULL;
    }
    if(value == root->data)
    {
        return root;
    }
    else if(value < root->data)
    {
          return search(root->left,value);
    }
    else
    {
          return search(root->right,value);
    }
}
  
 
int main()
{
   
struct node *p = create_node(10);
struct node *p1= create_node(5);
struct node *p2= create_node(12);
struct node *p3= create_node(3);
struct node *p4= create_node(7);
struct node *p5= create_node(16);
// linked the root node with left and right children
 p->left = p1;
 p->right = p2;
 p1->left = p3;
 p1->right = p4;
 p2->right = p5;
        //these binary search tree look like these
        //              (p)10
        //              /    \
        //             /      \
        //        (p1)5       (p2)12
        //        /    \       /    \
        //   (p3)3   (p4)7   NULL   (p5)16
     struct node * n = search(p,7);
     if(n != NULL)
     {
         printf("element %d found",n->data);
     }
     else 
     {
         printf("element not found ");
     }
     
     
}

