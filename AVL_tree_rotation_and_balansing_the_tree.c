#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node * left;
    struct node * right;
    int hight;
};
void inoreder_traversal(struct node * root)
{
    if(root!=NULL)
    {
       
        inoreder_traversal(root->left);
         printf("%d  ",root->key);
        inoreder_traversal(root->right);
       
        

    }
}

int get_hight(struct node * n)
{
    if(n == NULL)
    {
        return 0;
    }
    return n->hight;
}

struct node * create_node(int key )
{
    struct node *n ;
    n = (struct node *) malloc(sizeof(struct node));
    n->key= key ;
    n->left = NULL;
    n->right = NULL;
    n->hight = 1;
    return n;
}

int max(int a , int b)
{
    if(a<b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int get_balance_factor(struct node * n)
{
  if(n == NULL)
  {
      return 0;
  }
  return get_hight(n->left) - get_hight(n->right);
}

struct node * right_rotate(struct node * y)
{
    struct node * x = y->left;
    struct node * t2 = x->right;

    x->right = y;
    y->left  = t2;

    y->hight =max(get_hight(y->right),get_hight(y->left) ) + 1;
    x->hight =max(get_hight(x->right),get_hight(x->left) ) + 1;

    return x;
}

struct node * left_rotate(struct node * x)
{
    struct node * y =x->right;
    struct node * t2 =y->left;
    
    y->left  = x;
    x->right = t2;
    

    y->hight =max(get_hight(y->right),get_hight(y->left) ) + 1;
    x->hight =max(get_hight(x->right),get_hight(x->left) ) + 1;
    
    return y;
}

struct node * insert(struct node * node , int key)
{
    if( node==NULL)
    
        return create_node(key);
    
    if(key < node->key)
    
        node->left = insert(node->left,key);
    
    else if(key > node->key)
    
        node->right = insert(node->right,key);
    
        return node;
    node->hight = 1 + max(get_hight(node->left),get_hight(node->right));
    int bf = get_balance_factor(node);

    //left left insertion  case
    if( bf > 1  && key < node->left->key)
    {
        right_rotate(node);
    }
    //right right insertion  case
    if( bf < -1  && key > node->right->key)
    {
        right_rotate(node);
    }
    //left right insertion case
     if( bf > 1  && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        right_rotate(node);
    }
    // right left insertion case
     if( bf < -1  && key > node->left->key)
    {
        node->right = right_rotate(node->right);
        left_rotate(node);
    }
    return node;

}

int main()
{
    struct node * root = NULL;
    root = insert(root,45);
    root = insert(root,5);
    root = insert(root,7);
    root = insert(root,8);
    inoreder_traversal( root);

    return 0;
}

    
