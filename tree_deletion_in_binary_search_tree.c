
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

struct node * inorder_predecessor(struct node * root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;

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

struct node * delete_node(struct node * root , int value)
{ struct node * ipre ;
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

   if(value < root->data)
   {
       root->left = delete_node(root->left,value);
   }
   else if(value > root->data)
   {
     root->right =  delete_node(root->right,value);
   }
   else
   {
       ipre = inorder_predecessor(root);
       root->data  = ipre->data;
      root->left = delete_node(root->left,ipre->data);
   }
   return root;

}



 
int main()
{
   
struct node *p = create_node(10);
struct node *p1= create_node(5);
struct node *p2= create_node(11);
struct node *p3= create_node(3);
struct node *p4= create_node(7);
struct node *p5= create_node(15);
struct node *p6= create_node(50);
// linked the root node with left and right children
 p->left = p1;
 p->right = p2;
 p1->left = p3;
 p1->right = p4;
 p2->left = p5;
 p2->right = p6;
        //these binary search tree look like these
        //              (p)10
        //              /    \
        //             /      \
        //        (p1)5       (p2)20
        //        /    \       /    \
        //   (p3)3   (p4)7   (p5)15   (p6)50
    inoreder_traversal(p);
    delete_node(p,7);
     delete_node(p,11);
    printf("\n");
    inoreder_traversal(p);
     
     
}

