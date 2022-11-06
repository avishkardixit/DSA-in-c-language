#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node * left,*right;
};
typedef struct node * NODEPTR;

NODEPTR create()
{
    NODEPTR tree = NULL, newnode, p;
    char ans;

    do
    {
        newnode = (NODEPTR)malloc(sizeof(struct node));
        printf("data : ");
        scanf("%d",&newnode->info);
        newnode->left=newnode->right=NULL;
        if(tree == NULL)
        {
            tree = newnode;
        }
        else
        {
             p=tree;
             while(p != NULL)
             {
                 if(newnode->info < p->info)
                 {
                     if(p->left == NULL)
                     {  
                         p->left = newnode;
                         break;
                     }
                     p = p->left;
                 }
                 else
                 {
                     if(p->right == NULL)
                     {
                         p->right = newnode;
                         break;
                     }
                     p = p->right;
                 }
             }
        }
        printf("press Y to continue : ");
        scanf("%c",&ans);
        ans = getchar();
        fflush(stdin);
    }while(ans == 'Y' || ans =='y');
    return(tree);
}

int is_bst(NODEPTR tree)
{
    static NODEPTR prev;
    if(tree != NULL)
    {
        if(!is_bst(tree->left))
        {
              return 0;
        }
        if(prev != NULL && tree->info <= prev->info)
        {
            return 0;
        }
        prev = tree;
        return is_bst(tree->right);
        
    }
    else
    {
        return 1;
    }
}


void inorder(NODEPTR tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d\t", tree->info);
        inorder(tree->right);
    }
}

int main()
{
    NODEPTR tree = NULL,p;
    tree = create();

    inorder(tree);

    if(is_bst(tree)==1)
    {
        printf("tree is binary search tree");
    }
    else
    {    
        printf("tree is not bst");

    }



}