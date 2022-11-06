#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left, *right;
};
typedef struct node *NODEPTR;

NODEPTR create_node(int data)
{
   NODEPTR newnode =(NODEPTR)malloc(sizeof(struct node));
   newnode->info=data;
   newnode->left=NULL;
   newnode->right=NULL;
}

void inoder(NODEPTR tree)

{
    if (tree != NULL)
    {
        inoder(tree->left);
        printf("%d \t", tree->info);
        inoder(tree->right);
    }
}

int  compare(NODEPTR p1,NODEPTR p2)
{
     if(p1==NULL && p2==NULL )
     {
         return 1;
     }

     return (p1 && p2) &&  ( p1->info == p2->info) &&
            compare(p1->left,p2->left) &&
            compare(p1->right,p2->right);

}

NODEPTR copy( NODEPTR tree)
{
    if(tree==NULL)
    {
        return NULL;
    }
    else
    {
        NODEPTR newnode = create_node(tree->info);
        newnode->left=copy(tree->left);
        newnode->right=copy(tree->right);
        return newnode;
    }
}

int main()
{

  //first tree
    NODEPTR p = create_node(10);
     NODEPTR p1 = create_node(7);
      NODEPTR p2 = create_node(11);
       NODEPTR p3 = create_node(5);
        NODEPTR p4 = create_node(9);
         NODEPTR p5 = create_node(12);
    
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;

  //second tree
     NODEPTR q = create_node(10);
     NODEPTR q1 = create_node(70);
      NODEPTR q2 = create_node(11);
       NODEPTR q3 = create_node(5);
        NODEPTR q4 = create_node(9);
         NODEPTR q5 = create_node(12);
    
    q->left=q1;
    q->right=q2;
    q1->left=q3;
    q1->right=q4;
    q2->right=q5;
    printf("\noriginal tree : \n");
    inoder(p);

    if(compare(p,q))
    {
        printf("\n both trees are similar to each other ");

    }
    else
    {
        printf("\n TREES have some different nodes tree is diiferent\n");
    }
    inoder(q);

    NODEPTR clone =(NODEPTR)malloc(sizeof(struct node));


    clone = copy(p);
    printf("\nexact copy of original tree : \n");
    inoder(clone);

}