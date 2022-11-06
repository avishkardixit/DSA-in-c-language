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

void preorder_traversal(struct node * root)
{
    if(root != NULL )
    {
        printf("%d \n",root->data);
         preorder_traversal(root->left);
         preorder_traversal(root->right);

    }
}


int main()
{


struct node *p = create_node(1);
struct node *p1= create_node(2);
struct node *p2= create_node(4);
struct node *p3= create_node(8);
struct node *p4= create_node(76);
struct node *p5= create_node(23);

// linked the root node with left and right children
 p->left = p1;
 p->right = p2;
 p1->left = p3;
 p1->right = p4;
 p2->left = p5;
 preorder_traversal(p);
}