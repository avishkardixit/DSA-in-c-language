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

void inoreder_traversal(struct node * root)
{
    if(root!=NULL)
    {
       
        inoreder_traversal(root->left);
         printf("%d",root->data);
        inoreder_traversal(root->right);
       
        

    }
}
int main()
{
   
struct node *p = create_node(1);
struct node *p1= create_node(2);
struct node *p2= create_node(4);

// linked the root node with left and right children
 p->left = p1;
 p->right = p2;
 inoreder_traversal(p);
}