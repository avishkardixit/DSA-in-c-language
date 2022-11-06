//the binary search tree is a binary tree of which left subtree is less than root and right 
//subtree is greather than root

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
         printf("%d ",root->data);
         inoreder_traversal(root->right);
    }
  
}

int is_binary_search_tree(struct node * root)
{ static struct node * prev = NULL;
    if(root!=NULL)
    {
       if(!is_binary_search_tree(root->left))
       {
           return 0;
       }
       if(prev!=NULL  && root->data <= prev-> data)
       {
           return 0;
       }
       prev = root;
       return is_binary_search_tree(root->right);
        

    }
    else
    {
        return 1;
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
 if(is_binary_search_tree(p))
 {
     printf("given tree is binarry search tree");
 }
 else
 {
     printf("given tree is NOT binarry search tree");
 }
}