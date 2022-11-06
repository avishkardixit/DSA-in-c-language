#include<stdio.h>
#include<stdlib.h>

struct node {
 
       int data;
       struct node * left,*right;
};
typedef struct node * NODEPTR;

NODEPTR create()
{
    NODEPTR root=NULL, newnode ,temp;
    char ans;

    do{
        newnode =(NODEPTR)malloc(sizeof(struct node));
        printf("enter data :");
        scanf("%d",&newnode->data);
        newnode->left=newnode->right=NULL;

        if(root==NULL)
        {
            root=newnode;
        }
        else
        {
            temp=root;
            while(temp!=NULL)
            {
                if(newnode->data<temp->data)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    temp=temp->left;
                }
                else if(newnode->data>temp->data)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                     temp=temp->right;
                } 
            }
        }
        printf("press Y to continue N to stop :");
        scanf("%c",&ans);
        ans =getchar();
        fflush(stdin);

    }while(ans == 'y' || ans =='Y');
    return (root);

}

void inoder(NODEPTR root)
{
    if(root!=NULL)
    {
        inoder(root->left);
        printf("%d\t",root->data);
        inoder(root->right);
    }
}

int main()
{
    NODEPTR root = NULL,temp;
    root= create();
    inoder(root);

}
