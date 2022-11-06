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
        printf("enter data : ");
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
        printf("Do youwant to continue(Y/N)?");

        scanf("%c", &ans);
        ans = getchar();
        fflush(stdin);
    } while (ans == 'Y' || ans == 'y');
    return (tree);
}

NODEPTR delete (NODEPTR tree, int val)
{
    if (tree == NULL)
        return NULL;
    if (tree->info < val)
        tree->right = delete (tree->right, val);

    else if (tree->info > val)
        tree->left = delete (tree->left, val);

    else// element to deleted is FOUND 
    {
        if (tree->left == NULL && tree->right == NULL)  //element is at leaf node
        {
            free(tree);
            return NULL;
        }

        else if (tree->left == NULL)
        {
            NODEPTR temp = tree->right;
            free(tree);
              tree = temp;
            
        }

        else if (tree->right == NULL)
        {
            NODEPTR temp = tree->left;
            free(tree);
            tree=temp;
            
        }

        else 
        {
            int min = minimum(tree->right);
            tree->info = min;
            tree->right = delete (tree->right, min);
        }
    }
    return tree;
}
int minimum(NODEPTR tree)
{
    if (tree->left == NULL)
    {
        return tree->info;
    }
    minimum(tree->left);
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
    NODEPTR tree = NULL, p;
    tree = create();
    int key;
    printf("Enter value to delete");
    scanf("%d", &key);
    p = delete (tree, key);
    if (p != NULL)
        printf("\n%d is deleted from tree", key);
    else
        printf("\n%d is not presented in the tree ", key);
    printf("\n inorder traversal \n");
    inorder(tree);
}
