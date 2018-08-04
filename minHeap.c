#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int nodeValue;
	struct node *left;
	struct node *right;
//	int ind;
};

struct node* root=NULL;
int NumberOfNodes=1;
int binaryArray[10]={0,0,0,0,0,0,0,0,0,0};

struct node* newNode(int data)
{	
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->nodeValue = data;
  node->left = NULL;
  node->right = NULL;
//  node->ind=NumberOfNodes;
  return(node);
}

int NumberToBinary(int num)
{ 
	int counter =9;
	while(num != 0){
		binaryArray[counter]=num%2;
    	counter--;
    	num /= 2;
	}
	return counter+1;
}

//void swap(struct node* a,struct node* b)
//{
//	int temp = a->nodeValue;
//	a->nodeValue = b->nodeValue;
//	b->nodeValue = temp;
//}

int HeightOfTree(int NumberOfNodes)
{
	int temp=0;
	temp=(int)(log(NumberOfNodes)/log(2));
	return temp;
}

void heapify(struct node* root,in)
{
	int temp;

	if(root->left != NULL && root->right!=NULL && root->left->nodeValue < root->nodeValue && root->left->nodeValue < root->right->nodeValue)
	{
		temp = root->nodeValue;
		root->nodeValue = root->left->nodeValue;
		root->left->nodeValue = temp;
		heapify(root->left);
	}
	else if(root->right != NULL && root->left !=NULL && root->right->nodeValue < root->nodeValue)
	{
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
	printf("\nInserting %d\n",key);
	int k=0;
	if(root == NULL)//only for first node
	{
		NumberOfNodes=2;
		root=newNode(key);
		return root;
	}
	k=NumberToBinary(NumberOfNodes);

	struct node* Node= root;
	struct node* temp= newNode(key);
//	i=9-HeightOfTree(NumberOfNodes);
	int i=k+1;//i points to the beginning of the binary part
	int j=i;
	while(i<9)
	{
		Node=(binaryArray[i]==0)?(Node->left):(Node->right);
		i++;
	}
	struct node* ptr=Node;
	if(binaryArray[9]==0) 
	{
		Node->left=temp;
	}
	else
	{
		Node->right=temp;
	}
	NumberOfNodes++;
	printf("\nNumber of nodes= %d\n",NumberOfNodes);
	//heapify the above node
	heapify(ptr);
	printf("\n-------------------\n");
	return;	

}

int extract_min(struct node* root) //there might be some problem with extract_min
{
	int lastVal=0;//variable to store the nodevalue of the last node

	int min=root->nodeValue;
	//swaping the last node and deleting it
//	int* binaryArray=NumberToBinary(NumberOfNodes);
	int i=NumberToBinary(NumberOfNodes)+1;
	struct node* Node= root;
//	int i=9-HeightOfTree(NumberOfNodes);//i points to the beginning of the binary part
	while(i<9)
	{
		Node=(binaryArray[i]==0)?(Node->left):(Node->right);
		i++;
	}
	if(binaryArray[9]==0)
	{
		lastVal=Node->left;
		Node->left=NULL;
	}
	else
	{
		lastVal=Node->right;
		Node->right=NULL;	
	}
	NumberOfNodes--;
	root->nodeValue=lastVal;
	
	//heapify root
	heapify(root);
	return min;
}

int main()
{	
	
	root=InsertNode(root,5,HeightOfTree(NumberOfNodes));
	printf("\nNow at root node: %d\n",root->nodeValue);
	root=InsertNode(root,6,HeightOfTree(NumberOfNodes));
	printf("now at root node: %d\n",root->nodeValue);
	printf("now at root->left node: %d",root->left->nodeValue);
	root=InsertNode(root,3,HeightOfTree(NumberOfNodes));
	printf("now at root node: %d\n",root->nodeValue);
	printf("now at root->left node: %d",root->left->nodeValue);
	printf("now at root->right node: %d",root->right->nodeValue);
//	InsertNode(1);
//	InsertNode(6);
//	InsertNode(62);
//	InsertNode(63);InsertNode(43);InsertNode(621);
	printf("\n Number of Nodes =%d",NumberOfNodes);
	printf("\nRoot Node Value=%d\n",root->nodeValue);

//	printf("\nExtract min Value = %d\n",extract_min(root));
	return 0;
}
