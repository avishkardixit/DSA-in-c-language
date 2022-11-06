#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};
typedef struct node * NODEPTR;

NODEPTR create()
{
    NODEPTR tree = NULL, newnode, p;
    char ans;

    do
    {
        newnode = (NODEPTR)malloc(sizeof(struct node));
        printf("enter data \n");
        scanf("%d", &newnode->info);
        newnode->left = newnode->right = NULL;
        if (tree == NULL)
        {
            tree = newnode;
        }
        else
        {
            p = tree;
            while (p != NULL)
            {
                if (newnode->info < p->info)
                {
                    if (p->left == NULL)
                    {
                        p->left = newnode;
                        break;
                    }
                    p = p->left;
                }
                else
                {
                    if (p->right == NULL)
                    {
                        p->right = newnode;
                        break;
                    }
                    p = p->right;
                }
            }
        }
        printf("do you want to continue (Y/N)?");
        scanf("%c", &ans);
        ans = getchar();
        fflush(stdin);
    } while (ans == 'Y' || ans == 'y');
    return (tree);
}

//preoder traversal
void preoder(NODEPTR tree)
{
    if(tree != NULL)
    {
        printf("%d \t",tree->info);
        preoder(tree->left);
        preoder(tree->right);
    }
}

void postoder(NODEPTR tree)
{
    if(tree != NULL)
    {
        postoder(tree->left);
        postoder(tree->right);
        printf("%d \t",tree->info);
    }
}

void inoder(NODEPTR tree)
{
    if(tree != NULL)
    {
        inoder(tree->left);
        printf("%d \t",tree->info);
        inoder(tree->right);
    }
}

int main()
{
    NODEPTR tree = NULL;
    tree = create();
    
    printf("\n  preoder traversal is : \n");
    preoder(tree);

    printf("\n  postoder traversal is : \n");
    postoder(tree);

    printf("\n  inoder traversal is : \n");
    inoder(tree);

}    