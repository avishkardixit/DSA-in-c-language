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

void inoder(NODEPTR root)
{
    
    if(root != NULL)
    {
        inoder(root->left);
        printf("%d \t",root->data);
        inoder(root->right);
    }
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
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;

    printf("\n inoder traversal is :: \n");
    inoder(p);






}