
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

void insert(struct node * root , int value)
{
   struct node * prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(value == root->data)
        {
            printf("cannot insert the value that allready exist !!\n");
            return ;
        }
        else if(value < root->data)
        {
              root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node * new = create_node(value);
    if(value < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

void inoreder_traversal(struct node * root)
{
    if(root!=NULL)
    {
       
        inoreder_traversal(root->left);
         printf("%d ",root->data);
        inoreder_traversal(root->right);
       
        

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
    inoreder_traversal(p);
    printf("\n");
    insert(p,12);
    inoreder_traversal(p);
     
     
}

