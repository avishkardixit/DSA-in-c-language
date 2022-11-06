#include<stdio.h>
#include<malloc.h>
 
 struct node{

     int data;
     struct node * left;
     struct node * right;
 };
 typedef struct node * NODEPTR;

 NODEPTR create_node(int data)
{     NODEPTR n;
      n=(NODEPTR)malloc(sizeof(struct node ));
      n->data=data;
      n->left = NULL;
      n->right = NULL;
      return n;
}

int inoder(NODEPTR root)
{
     static int count;
    
    if(root != NULL)
    {
        inoder(root->left);
        if(root->left!=0 || root->right != 0)
        {
        count++;
        }
        inoder(root->right);
    }
    return count;
}
 
//         p(60)
//         /    \
//     p1(50)    p2(70)
//      /  \       \
// p3(25)  p4(55)   p5(80)

int main()
{
    NODEPTR p = create_node(60);
     NODEPTR p1 = create_node(50);
      NODEPTR p2 = create_node(70);
       NODEPTR p3 = create_node(25);
        NODEPTR p4 = create_node(55);
         NODEPTR p5 = create_node(80);
         NODEPTR p6 =create_node(90);
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;
    p3->left=p6;

    printf("\n inoder traversal is :: \n");
   int z=inoder(p);
   printf("%d",z);






}