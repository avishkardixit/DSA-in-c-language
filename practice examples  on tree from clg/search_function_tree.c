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

NODEPTR search(NODEPTR tree, int key)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (key == tree->info)
    {

        return tree;
    }

    else if (key < tree->info)
    {
        return search(tree->left, key);
    }
    else
    {
        return search(tree->right, key);
    }
}
int main()
{
    NODEPTR tree = NULL, p;
    tree = create();
    int key;
    printf(" enter value to search :");
    scanf("%d", &key);
    p = search(tree, key);
    if (p != NULL)
        printf("\n key is present in tree ");
    else
        printf("\n key is not present in the tree");
}
