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

void postoder(NODEPTR root)
{
    
    if(root != NULL)
    {
        postoder(root->left);
        postoder(root->right);
        printf("%d \t",root->data);
    }
}
 
//         p(67)
//         /    \
//     p1(7)    p2(6)
//      /  \       \
// p3(69)  p4(70)   p5(670)

int main()
{
    NODEPTR p = create_node(67);
     NODEPTR p1 = create_node(7);
      NODEPTR p2 = create_node(6);
       NODEPTR p3 = create_node(69);
        NODEPTR p4 = create_node(70);
         NODEPTR p5 = create_node(670);
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;

    printf("\npostoder traversal is :: \n");
    postoder(p);






}