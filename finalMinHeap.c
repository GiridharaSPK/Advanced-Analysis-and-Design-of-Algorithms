#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
  
struct Node
{
	int nodeValue;
    	struct Node *left;
	struct Node *right;
};

int NumberOfNodes = 1;
int binaryArray[10];


int NumberToBinary(int c){

	int i = 0;
	while(c!=0){

		binaryArray[i] = c%2;
		c = c/2;
		i++;
	}

	return (i-2);
}

void heapify(struct Node* root){

	int temp;

	if((root->left != NULL) && (root->right != NULL) && (root->left->nodeValue < root->nodeValue) && (root->left->nodeValue < root->right->nodeValue)){

			temp = root->nodeValue;
			root->nodeValue = root->left->nodeValue;
			root->left->nodeValue = temp;
			heapify(root->left);

	}else if((root->right != NULL) && (root->left != NULL) && (root->right->nodeValue < root->nodeValue)){

			temp = root->nodeValue;
			root->nodeValue = root->right->nodeValue;
			root->right->nodeValue = temp;
			heapify(root->right);
		
	}
	return;
}
struct Node* extractMin(struct Node* root)
{
	if(NumberOfNodes == 2)
	{
		printf("\nMinimum is %d\n",root->nodeValue);
		NumberOfNodes--;
		return NULL;
	}
	else if(NumberOfNodes > 2)
	{
		printf("\nMinimum is %d\n",root->nodeValue);
		struct Node* temp = root;
		int i = NumberToBinary(NumberOfNodes-1);
		while(i > 0)
		{
			if(binaryArray[i] == 0)
			{
				temp = temp -> left;	
			}
			else
			{
				temp = temp -> right;
			}
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
		return root;
	}
	else
	{
		return root;
	}		
}

struct Node* insert(struct Node *root,int key,int ind){

	if(root == NULL){

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->nodeValue = key;
		newNode->left = newNode->right = NULL;
		NumberOfNodes++;
		return newNode;	
	}

	int temp;
	if(binaryArray[ind]==0){

		if(root->nodeValue>key){

			temp = root->nodeValue;
			root->nodeValue = key;
			key = temp;
		}

		ind--;
		root->left = insert(root->left,key,ind);
		
	}else{

		if(root->nodeValue>key){

			temp = root->nodeValue;
			root->nodeValue = key;
			key = temp;
		}

		ind--;
		root->right = insert(root->right,key,ind);
		
	}
	return root;
}

void isEmpty(struct Node* root){

	if(root == NULL){

		printf("Is Empty\n");
	}else{

		printf("Is Not Empty\n");
	}
}


int main(){

	struct Node *heaproot = NULL;
	heaproot = insert(heaproot,5,NumberToBinary(NumberOfNodes));
	heaproot = insert(heaproot,14,NumberToBinary(NumberOfNodes));
	heaproot = insert(heaproot,31,NumberToBinary(NumberOfNodes));
	heaproot = insert(heaproot,26,NumberToBinary(NumberOfNodes));
	heaproot = insert(heaproot,14,NumberToBinary(NumberOfNodes));

	heaproot = extractMin(heaproot);
	printf("press ENTER to close.");
getchar();
}

