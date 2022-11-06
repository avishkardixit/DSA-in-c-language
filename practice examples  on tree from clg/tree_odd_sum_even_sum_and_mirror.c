// write a c program which will write sum off odd nodes in tree , sum of even nodes
//  in tree and mirror of original tree

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};
typedef struct node *NODEPTR;

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

void inorder(NODEPTR tree)
{
    if (tree != NULL)
    {
        inorder(tree->left);
        printf("%d\t", tree->info);
        inorder(tree->right);
    }
}
int odd;
int oddsum(NODEPTR tree)
{
    if (tree != NULL)
    {
        oddsum(tree->left);

        if (tree->info % 2 != 0)
            odd = odd + tree->info;

        oddsum(tree->right);
    }
    return odd;
}

int even;
int evensum(NODEPTR tree)
{
    if (tree != NULL)
    {
        evensum(tree->left);

        if (tree->info % 2 == 0)
            even = even + tree->info;

        evensum(tree->right);
    }
    return even;
}

void mirror(NODEPTR tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {

        NODEPTR temp;

        mirror(tree->left);
        mirror(tree->right);

        temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;
    }
}

int main()
{
    NODEPTR tree = NULL, p;
    tree = create();

    inorder(tree);

    int odd_num = oddsum(tree);
    printf(" \n sum of odd num : %d \n", odd_num);

    int even_num = evensum(tree);
    printf("\n sum of even num : %d \n", even_num);

    mirror(tree);

    printf("the tree after mirror is :");
    inorder(tree);
}