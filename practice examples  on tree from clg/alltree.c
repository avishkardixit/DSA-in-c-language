#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* left;
	struct node* right;
};
typedef struct node* NODEPTR;


NODEPTR Create()
{

	NODEPTR tree = NULL,p = NULL,newnode= NULL;
	char ans;
	do
	{
		
		newnode = (NODEPTR)malloc(sizeof(struct node));
		newnode->left = NULL;
		newnode->right = NULL;
		
		printf("Enter value :");
		scanf("%d",&newnode->info);
		
		
	
		if(tree==NULL)
		{
			tree = newnode;
			p = newnode;
		}
		else
		{
		 p = tree;
		  while(p!=NULL)
		  {
		  	if(newnode->info < p->info)
		  	{
		  		if(p->left == NULL)
		  		{
		  			p->left = newnode;
		  			break;
				}
				else
				  p=p->left;
			  }
			  else
			  {
			  	if(p->right==NULL)
			  	{
			  		p->right = newnode;
			  	  break;
				}
				else
				  p = p->right;
			  }
		  }
       }
		
		
		printf("Do you want to continue the list (y/n) : ?");
//fflush(stdin);
	
		scanf("%c",&ans);
		ans = getchar();
	}while(ans=='Y' || ans=='y');

	return (tree);
}

void Preorder(NODEPTR tree)
{
	if(tree!=NULL)
	{
	
	printf("%d\t",tree->info);
	Preorder(tree->left);
	Preorder(tree->right);
   }
}

void Inorder(NODEPTR tree)
{
	if(tree!=NULL)
	{
	
	Inorder(tree->left);
	printf("%d\t",tree->info);
	Inorder(tree->right);
   }
	
}

void Postorder(NODEPTR tree)
{
	if(tree!=NULL)
	{
	
	Postorder(tree->left);
	Postorder(tree->right);
	printf("%d\t",tree->info);
   }
}

NODEPTR Search(NODEPTR tree,int key)
{
	NODEPTR temp = tree;
	
	if((temp==NULL) || (temp->info==key))
	{
	
		return temp;
	}
	else
	{
		if(key < temp->info)
		{
			return Search(tree->left,key);
		}
		else
		{
		 return Search(tree->right,key);	
		}
	}
}

NODEPTR Insert(NODEPTR tree,int key)
{
	
   if(tree == NULL)
   {
      tree = (NODEPTR)malloc(sizeof(struct node));
	  tree->info = key;
	  tree->left = NULL;
	  tree->right = NULL;  	
   }	
   else
   {
   	if(key<tree->info)
   	{
   		tree->left = Insert(tree->left,key);
	  }
	   else
	   tree->right = Insert(tree->right,key);
	 return tree;  
   }
}

int Count_node(NODEPTR tree)
{
	int i =0;
	if(tree==NULL)
	{
		return 0;
		
	}
	else
	{
	    return (1 + Count_node(tree->left) + Count_node(tree->right));
	}
	
}

int Count_leaf_node(NODEPTR tree)
{
	int i =0;
	if(tree==NULL)
	{
		i= 0;
		
	}
	else
	{
		if((tree->left==NULL)&&(tree->right==NULL))
		{
			return(1);
		}
		else
	    return ( Count_leaf_node(tree->left) + Count_leaf_node(tree->right));
	}
	
}


int Count_Nonleaf_node(NODEPTR tree)
{
	int i =0;
	if(tree==NULL)
	{
		return 0;
		
	}
	else
	{
		if((tree->left==NULL)&&(tree->right==NULL))
		{
			return(0);
		}
		else
	    return (1+ Count_Nonleaf_node(tree->left) + Count_Nonleaf_node(tree->right));
	}
}
	
NODEPTR Delete(NODEPTR tree,int val)
	{
		if(tree->info > val)
		{
			tree->left=Delete(tree->left,val);
		}
		else if(tree->info<val)
		{
			tree->right = Delete(tree->right,val);
		}
		else
		{
			if(tree->left ==NULL && tree->right==NULL)
			{
				free(tree);
				return NULL;
			}
			else if(tree->right == NULL)
			{
				NODEPTR temp = tree->left;
				free(tree);
				return(temp);
			}
			else if(tree->left==NULL)
			{
				NODEPTR temp = tree->right;
				free(tree);
				return(temp);
				
			}
			else
			{
				int min=Min(tree->right);
				tree->info = min;
				tree->right=Delete(tree->right,min);
				
			}
			return tree;
		}
	}


int Min(NODEPTR tree)
{
    if(tree==NULL)
	{
		printf("Tree is Empty cannot deleted the element ");
		return -1;
	}
	else if(tree->left == NULL)
	{
	  return tree->info;	
	}	
	return Min(tree->left);
}

int Max(NODEPTR tree)
{
    if(tree==NULL)
	{
		printf("Tree is Empty cannot deleted the element ");
		return -1;
	}
	else if(tree->right == NULL)
	{
	  return tree->info;	
	}	
	return Max(tree->right);
}

NODEPTR copy(NODEPTR tree)
{
	NODEPTR P=NULL;
	if(tree!=NULL)
	{
	   P=(NODEPTR)malloc(sizeof(struct node));
	   P->info=tree->info;
	   P->left=copy(tree->left);
	   P->right=copy(tree->right);
	}
	return P;
}
int Sum(NODEPTR tree)
{
	if(tree==NULL)
	{
		return 0;
	}
	return (tree->info+Sum(tree->left)+Sum(tree->right));
}

int evensum(NODEPTR tree)
{
	static sum=0;
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		
		evensum(tree->left);
		if(tree->info%2 ==0)
		{
			sum=sum+tree->info;
			//printf("%d",sum);
		}
		evensum(tree->right);
	
	}
	return sum;
}

int oddsum(NODEPTR tree)
{
	static sum=0;
	if(tree==NULL)
	{
		return 0;
	}
	else
	{
		
		oddsum(tree->left);
		if(tree->info%2 ==1)
		{
			sum=sum+tree->info;
			//printf("%d",sum);
		}
		oddsum(tree->right);
	
	}
	return sum;
}

int Compare(NODEPTR t1,NODEPTR t2)
{
	 if(t1==NULL && t2==NULL)
	 {
	 	printf("Both tree are empty ");
	 	return 0;
	 }
	 else
	 {
	 	if(t1->info==t2->info)
	 	{
	 		return 1;
		 }
		 else
		 {
		 	return 0;
		 }
		 Compare(t1->left,t2->left);
		 Compare(t1->right,t2->right);
	 }
}
int main()
{  
	NODEPTR tree = NULL,root = NULL,P=NULL,t1=NULL,t2=NULL;
	int ch,key,n,cnt,leaf,non_leaf,min,max,del,sum=0,even,odd=0,status=0;
	while(1)
	{
	printf("\n");
	puts("--------------------TREE MENU--------------------");
	puts("1.create");
	puts("2.Preorder");
	puts("3.Inorder");
	puts("4.Postorder");
	puts("5.Search node");
	puts("6.Count node");
	puts("7.leaf node");
	puts("8.Non_leaf node");
	puts("9.Insert node");
	puts("10.Min element");
	puts("11.Max element");
	puts("12.Delete");
	puts("13.Copy tree");
	puts("14.Sum of nodes");
	puts("15.Sum of Even nodes");
	puts("16.Sum of Odd nodes");
	puts("17.Comapare");
	puts("20.Exit");
	puts("----------------------------------------------------");
	printf("\n");
	printf("Enter your choice :");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			
			 tree = Create();
			  break;
		case 2:
			   Preorder(tree);
			   break;
	    case 3:
			   Inorder(tree);
			   break;
		case 4:
			   Postorder(tree);
			   break;
		case 5:
			printf("Enter value :");
			scanf("%d",&key);
			 root = Search(tree,key);
			 if(root!=NULL)
			 {
			 	printf("%d value found\n ",root->info);
			 }
			 else
			 {
			 	printf("%d value not found \n",key);
			 }
			 
			   break;
		case 6:
			    cnt=Count_node(tree);
			    printf("%d node are present in tree\n",cnt);
			    break;
		case 7:
			    leaf=Count_leaf_node(tree);
			    printf("%d node are present in tree which is leaf node\n",leaf);
			    break;
		case 8:
			    non_leaf=Count_Nonleaf_node(tree);
			    printf("%d non-leaf node are present in tree  \n",non_leaf);
			    break;
			    
		case 9:
		       printf("Enter node to insert :");
		       scanf("%d",&n);
		       tree=Insert(tree,n);
		       printf("Node inserted successfully\n");
			   break;
			   
		case 10:
			    min=Min(tree);
			    printf("%d element is minimum element",min);
			    break;
		case 11:
			    max=Max(tree);
			    printf("%d element is maximum element",max);
			    break;
		case 12:
			   printf("Enter element to delete :");
			   scanf("%d",&del);
			  root= Delete(tree,del);
			  printf("%d element is deleted successfully ",del);
			  break;
		case 13:
		        P=copy(tree);
		        Inorder(P);
		        printf("\n");
		        Inorder(tree);
		        printf("Tree copied successfully");
		        break;
		case 14:
		        sum=Sum(tree);
				printf("sum of all nodes = %d",sum);
				break;
		case 15:
		        even=evensum(tree);
				printf("sum of even nodes = %d",even);
				break;
		case 16:
		        odd=oddsum(tree);
				printf("sum of odd nodes = %d",odd);
				break;
		case 17 :
		          t1=Create(); 	
				  t2=Create(); 
				  status = Compare(t1,t2); 
				  if(status ==1)
				  {
				  	printf("trees are equal ");
				   } 
				   else
				   {
				   	printf("Trees are not equal");
				   }
				   break;
		case 20:
			printf("Thanks for visiting  \n");
			return 0;
		default:
			printf("Invalid choice ");
		}
		
	}
}
