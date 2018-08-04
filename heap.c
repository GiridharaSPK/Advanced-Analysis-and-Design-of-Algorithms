#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

int count=0;
int binArray[20];

void heapify(struct node* root)
{
	int temp;

	if(root->left != NULL && root->right!=NULL && root->left->data < root->data && root->left->data < root->right->data)
	{
		temp = root->data;
		root->data = root->left->data;
		root->left->data = temp;
		heapify(root->left);
	}
	else if(root->right != NULL && root->left !=NULL && root->right->data < root->data){			
		temp = root->data;
		root->data = root->right->data;
		root->right->data = temp;
		heapify(root->right);
	}
	return;
}

struct node* extractMin(struct node* root)
{
	if(count == 2)
	{
		printf("Minimum is %d\n",root->data);
		count--;
		return NULL;
	}
	else if(count > 2)
	{
		printf("Minimum is %d\n",root->data);
		struct node* temp = root;
		int i = NumberToBinary(count-1);
		while(i > 0)
		{
			temp=(binArray[i] == 0)?(temp->left):(temp->right);
			i--;
		}
		if(binArray[i] == 0)
		{
			root -> data = temp -> left -> data;
			temp -> left = NULL;
		}
		else
		{
			root -> data = temp -> right -> data;
			temp -> right = NULL;
		}
		count--;
		heapify(root);
		return root;
	}
	else
	{	
		return root;
	}		
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

struct node* insert(struct node *root,int value,int i)
{
	if(root == NULL)
	{
		struct node* newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = value;
		newNode->left = newNode->right = NULL;
		count++;
		return newNode;	
	}

	int temp;
	if(binArray[i]==0)
	{
		if(root->data>value)
		{
			temp = root->data;
			root->data = value;
			value = temp;
		}
		i--;
		root->left = insert(root->left,value,i);
	}
	else
	{
		if(root->data>value)
		{
			temp = root->data;
			root->data = value;
			value = temp;
		}
		i--;
		root->right = insert(root->right,value,i);
	}
}

int NumberToBinary(int num)    
{
	int temp=0;
	while(num!=0)
	{
		binArray[temp]=num%2;
		num=num/2;
		temp+=1;
	}
	return temp-2;
}

int main()
{
	struct node *root1 = NULL;
	
	root1 = insert(root1,5,NumberToBinary(count));
	root1 = insert(root1,14,NumberToBinary(count));
	root1 = insert(root1,3,NumberToBinary(count));
	root1 = insert(root1,2,NumberToBinary(count));
	root1 = insert(root1,1,NumberToBinary(count));
	root1 = extractMin(root1);
	inorder(root1);		
	
	return 0;
}

