#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left , * right;

};
typedef struct node * NODEPTR;

NODEPTR create_node(int data)
{
    NODEPTR n;
    n = (NODEPTR)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}


int insert(NODEPTR root,int key)
{
    NODEPTR prev = NULL;


     while(root!=NULL)
    {
              prev=root;
          
          if(key==root->data)
          {
              return 0;
          }
          else if(key<root->data)
          {
              root=root->left;
          }
          else 
          {
              root=root->right;
          }
    }      
        NODEPTR new=create_node(key);   
        if(key<prev->data)
        {
              prev->left=new;
         
        }
        else
        {
              prev->right=new;
        }

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

int main()
{
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
    
    insert(p,8);

    inoder(p);


}