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
 
//         p(10)
//         /    \
//     p1(7)    p2(11)
//      /  \       \
// p3(5)  p4(9)   p5(12)

int is_bst(NODEPTR root)
{
    static NODEPTR prev;
    if(root != NULL)
    {
        if(!is_bst(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return is_bst(root->right);

    }
    else
    {
        return 1;
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

    if(is_bst(p)==1){
        printf("\nthe tree is binary search tree\n");
    }
    else{
        printf("\ntree is not binary search tree\n");
    }


    printf("inoder traversal is : \n");
    inoder(p);


  






}