#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>


struct node
{
	int nodeValue;
	struct node *left;
	struct node *right;
};

struct node* root=NULL;
int NumberOfNodes=0;
int binaryArray[10]={0,0,0,0,0,0,0,0,0,0};

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->nodeValue = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}

void heapify(struct node* root)
{
	int temp;

	if(root->left != NULL && root->left->nodeValue < root->nodeValue && root->left->nodeValue < root->right->nodeValue)
	{
		temp = root->nodeValue;
		root->nodeValue = root->left->nodeValue;
		root->left->nodeValue = temp;
		heapify(root->left);
	}
	else if(root->right != NULL && root->right->nodeValue < root->nodeValue){			
		temp = root->nodeValue;
		root->nodeValue = root->right->nodeValue;
		root->right->nodeValue = temp;
		heapify(root->right);
	}
	return;
}

//struct node* InsertNode(struct node *root, int NumberOfNodes, int key, int index)
void InsertNode(int key)
{
	if(NumberOfNodes<4)
	{
		if(root == NULL)
		{
//			struct node* newNode = (struct node*)malloc(sizeof(struct node));
//			newNode->nodeValue = key;
//			newNode->left =NULL;
//			newNode->right = NULL;
			NumberOfNodes=1;
			root=newNode(key);
			return ;
		}
		else if(NumberOfNodes==1)
		{
			root->left=newNode(key);
			NumberOfNodes=2;
			return;	
		}
		else if(NumberOfNodes==2)
		{
			root->right=newNode(key);
			NumberOfNodes=3;
			return;
		}
		else 
		{
			(root->left)->left=newNode(key);
			NumberOfNodes=4;
			return;
		}
	}

	int i=NumberToBinary(NumberOfNodes);	
	printf("i =%d\n", i);
	printf("Numberofnodes=%d\n",NumberOfNodes);
	struct node* Node= root;
	struct node* temp= newNode(key);
	
	while(i!=0)
	{
//		Node=(binaryArray[i]==0)?Node->left:Node->right;
		if(binaryArray[i]==0){
			Node=Node->left;
		}
		else{
			Node=Node->right;
		}
		i--;
	}	
	
	if(binaryArray[i]==0)
		Node->left=temp;
	else
		Node->right=temp;
		
//	heapify(root);
	NumberOfNodes++;
	return;
//	return NULL;
}

int NumberToBinary(int num)
{
	int i=0;
	while(num!=0)
	{
		binaryArray[i]=num%2;
		num=num/2;
		i++;
	}
	return i-2;
}

void swap(struct node* a,struct node* b){
  int temp = a->nodeValue;
  a->nodeValue = b->nodeValue;
  b->nodeValue = temp;
}

int extract_min(struct node* root)
{
	heapify(root);
	if(NumberOfNodes == 2)
	{
//		printf("%d\n",root->nodeValue);
		NumberOfNodes--;
		return root->nodeValue;
	}
	else if(NumberOfNodes > 2)
	{
//		printf("%d\n",root->nodeValue);
		struct node* temp = root;
		int i = NumberToBinary(NumberOfNodes-1);
		while(i > 0)
		{
			temp=(binaryArray[i] == 0)?(temp->left):(temp->right);
			i--;
		}
		if(binaryArray[i] == 0)
		{
			root -> nodeValue = temp -> left -> nodeValue;
			temp -> left = NULL;
		}
		else
		{
			root -> nodeValue = temp -> right -> nodeValue;
			temp -> right = NULL;
		}
		NumberOfNodes--;
		heapify(root);
		return root->nodeValue;
	}
	else
	{	
		return root->nodeValue;
	}
}

//int Height(int Number)
//{
//	int temp=0;
//	temp=log(Number)/log(2);
//	return temp;
//}

int main()
{
	int k;
	InsertNode(3);
//	printf("%d\n",root->nodeValue);
	printf("Number of Node= %d\n",NumberOfNodes);
//	for(k=0;k<10;k++)
//	printf("%d  ",binaryArray[k]);
	InsertNode(4);
	printf("\n Number of nodes= %d",NumberOfNodes);
	InsertNode(5);
	printf("\n Number of Nodes =%d",NumberOfNodes);
	InsertNode(6);
	printf("\n Number of Nodes =%d",NumberOfNodes);
	printf("\nRoot Node Value=%d\n",root->nodeValue);
	printf("\nExtract min Value = %d\n",extract_min(root));
	return 0;
}
