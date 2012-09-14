/*
 * tree.c
 * Binary Search tree
 *  Created on: Jul 14, 2012
 *      Author: vijay
 */

#include<stdio.h>
#include<stdlib.h>


#define bool  int
#define TRUE 1
#define FALSE 0
#define max(a,b) a > b ? a : b
// A node of tree

typedef struct node
{
  struct node *left;
  struct node *right;
  int data;
}node;

/* Determines the Height of the Tree
 * Length of the Longest path from root to leaf node
 */
int height(node *root)
{

	static int max;

	if (root == NULL)
		return 0;

	max = max(1 + height(root->left),1 + height(root->right));

   return max;
}
int leafs(node *root)
{
	static int count=0;

	if(root == NULL)
		return count;

	leafs(root->left);

	if(root->left == NULL && root->right ==NULL)
	{
		count++;
		printf("%d ", root->data);
	}


	leafs(root->right);

	return count;
}
void boundary_traversal(node **_root,node *root)
{
	static int side=0; // 0 --> L and 1 ---> R

	if(*_root ==NULL)
	{
		// if tree is really empty
		return;
	}

	if(root == NULL && *_root != NULL)
	{
		if (side == 0 )
		{
		root = *_root;
		leafs(root->left->right);
		leafs(root->right);
		return;
		}
		else
		{
			return ;
		}
	}
	else
	{
		if(side ==0 )
		{
			printf(" %d ",root->data);
			boundary_traversal(_root,root->left);
			side = 1;
		}

		printf("MOVING ON THE RIGHT SIDE");
//		root =
		boundary_traversal(_root,root->right);
		printf(" %d ",root->data);

	}
}
void inorder(node *root)
{
	if( root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void level_order_traversal()
{
	/* to do */
}

void depth_first_search()
{

}

// Code to insert in to Binary Search tree
// Keeping the Tree Balanced
void insert_bst_avl(node **root, int data)
{

}

int getbf(node *root)
{
	int bf=0;
	bf = (height(root->left)) - (height(root->right));
	return bf;
}

// i/p : Takes root of the tree
// o/p : Boolean value indicating whether Tree is Balanced or not

bool isBalanced(node *root)
{
	bool result=FALSE;
	int bfactor;

	// An Empty tree is always balanced
	if(root == NULL)
	    return TRUE;

	// Check Balance Factor of root node
	bfactor = getbf(root);

	// IF Balance Factor of Root is (-1,0,1) and its left & right subtree are balanced then
	// its TRUE that the tree is also balanced
	if ( abs (bfactor) < 2 && isBalanced(root->left) && isBalanced(root->right))
	{
		result=TRUE;
	}
	else
	{
		result=FALSE;
	}

	return result;
}

// Functions to readjust tree nodes

void rotateL(node **root)
{
//	node *root;
	int data;
	node *right;
//	root = *_root;
//	printf("\nLeft Rotate at %d",(*root)->data);

	data = (*root)->data;
	right = (*root)->right;
	(*root)->data = right->data;
	(*root)->right = right->right;
	right->right = NULL;

	right->data = data;
	right->right = right->left;

	right->left = (*root)->left;
	(*root)->left = right;
}

void rotateR(node **root)
{
	int data;
	node *left;
//	node *root;
//	root = *_root;
//	printf("\nRight Rotate at %d",(*root)->data);

	data = (*root)->data;
	left = (*root)->left;

	(*root)->data = left->data;
	(*root)->left = left->left;
	left->left = NULL;

	left->data = data;
	left->left = left->right;
	left->right = (*root)->right;
	(*root)->right = left;
}

void rebalance(node **root)
{
//	node *root=*_root;
	int bfactor;

	if((*root) == NULL)
	    return;

	// Check Balance Factor of root node
	bfactor = getbf(*root);

	if(abs(bfactor) < 2)
	{
		rebalance(&((*root)->left));
		rebalance(&((*root)->right));
	}
	else
	{
		// root is now pointing to the unbalanced node

		if (bfactor < 0) // Right Child is heavy
		{
			if( getbf((*root)->right) < 0)
			{
//				printf("\nRight child's Right subtree is heavy");
				// Case of Single Left Rotation
				rotateL(root);
			}
			else
			{
				// Case of One Right rotation @ root->right and Left Rotation at root
//				printf("\nRight child's Left subtree is heavy");
				rotateR((&((*root)->right)));
				rotateL(root);
			}
		}
		else // Left Child is heavy
		{
			if(getbf((*root)->left) > 0)
			{
//				printf("\nLeft child's Left subtree is heavy");
				// Case of Single Right Rotation
				rotateR(root);
			}
			else
			{
				// Case of One Left rotation @ root->left and Right Rotation at root
//				printf("\nLeft child's Right subtree is heavy");
				rotateL(&((*root)->left));
				rotateR(root);
			}
		}
		fflush(stdout);
	}
}
// read tree data from file

void read_tree_from_file(/*FILE *fp*/)
{

}
void insert_bst(node **root, int data)
{
	node *tmp=*root,*new,*tmpr;
	tmpr = tmp;
	// create new node
	new = (node *) malloc(sizeof(node));
	new->left = new->right = NULL;
	new->data = data;

	// reach the correct place
	while(tmp!=NULL )
	{
		// tmpr is used here to keep track of potential parent node of the newly inserted node
		tmpr = tmp;
 		if(data < tmp->data)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}

	if(data < tmpr->data)
	{
		tmpr->left = new;
	}
	else
	{
		tmpr->right = new;
	}
}


node *create_bst(node **root)
{
	int data;
	bool isbal;
	// 2^3-1 = 7 level
	if(*root == NULL)
	{
		*root = (struct node *) malloc(sizeof(struct node));
		fflush(stdout);
		printf("Enter data for root node :-");
		fflush(stdout);
		scanf("%d",&data);
		(*root)->left = (*root)->right = NULL;
		(*root)->data=data;
		data=0; // reset
	}
	while(TRUE)
	{
		fflush(stdout);
		printf("\nEnter data : -");
		fflush(stdout);
		scanf("%d",&data);
		if (data < 0)
			break;
		insert_bst(root,data);
		isbal=isBalanced(*root);
//		printf("\n After Inserting Data %d Tree ",data);
//		isbal ? printf(" is Balanced") : printf(" became disBalanced");
//		fflush(stdout);

		/*Invoking selfbalance*/
		if(!isbal)
		{
//			printf("Height of Tree Before Balancing %d",height(*root));
			rebalance(root);
//			printf("Height of Tree After Balancing %d",height(*root));
		}
	}

	return *root;
}


int main()
{
  node *_root;
  bool isbal=FALSE;
  int leafs_n;
  _root=NULL;
  _root=create_bst(&_root);
  printf("\n\ninorder traversal :- ");
  inorder(_root);
  printf("\nHeight of Tree rooted @ %d is %d \n",_root->data,height(_root));
  printf("\n Leafs nodes =");
  leafs_n=leafs(_root);
  printf("\n Leafs_N  = %d",leafs_n);
  printf("\n\nBoundary traversal :- ");
  boundary_traversal(&_root,_root);
//  isbal=isBalanced(_root);
//  printf("\nTree Looks ");
//  isbal ? printf("Balanced") : printf("DisBalanced");
  return 0;
}
