#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
  
struct Node
{
	int key;
    struct Node *left, *right;
};

int count = 1;
int num_nodes[100];


int conversion(int c){

	int i = 0;
	while(c!=0){

		num_nodes[i] = c%2;
		c = c/2;
		i++;
	}

	return (i-2);
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->key);
        inorder(root->right);
    }
}

void heapify(struct Node* root){

	int temp;
	
	printf("%d\n",root->key);

	if((root->left != NULL) && (root->left->key < root->key)){
		
		if(root->right==NULL)
		{
			temp = root->key;
			root->key = root->left->key;
			root->left->key = temp;
		}
		else if(root->left->key < root->right->key)
		{
			temp = root->key;
			root->key = root->left->key;
			root->left->key = temp;
			heapify(root->left);
		}

			

	}else if((root->right != NULL)  && (root->right->key < root->key)){

			temp = root->key;
			root->key = root->right->key;
			root->right->key = temp;
			heapify(root->right);
		
	}
	return;
}
struct Node* extractMin(struct Node* root)
{
	if(count == 2)
	{
		printf("Minimum is %d\n",root->key);
		count--;
		return NULL;
	}
	else if(count > 2)
	{
		printf("Minimum is %d\n",root->key);
		struct Node* temp = root;
		int i = conversion(count-1);
		while(i > 0)
		{
			if(num_nodes[i] == 0)
			{
				temp = temp -> left;	
			}
			else
			{
				temp = temp -> right;
			}
			i--;
		}
		if(num_nodes[i] == 0)
		{
			root -> key = temp -> left -> key;
			temp -> left = NULL;
		}
		else
		{
			root -> key = temp -> right -> key;
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

struct Node* insert(struct Node *root,int value,int i){


	if(root == NULL){

		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->key = value;
		newNode->left = newNode->right = NULL;
		count++;
		return newNode;	
	}

	int temp;
	if(num_nodes[i]==0){

		if(root->key>value){

			temp = root->key;
			root->key = value;
			value = temp;
		}

		i--;
		root->left = insert(root->left,value,i);
		
	}else{

		if(root->key>value){

			temp = root->key;
			root->key = value;
			value = temp;
		}

		i--;
		root->right = insert(root->right,value,i);
		
	}
	
}

void isEmpty(struct Node* root){

	if(root == NULL){

		printf("True\n");
	}else{

		printf("False\n");
	}
}


int main(){

	struct Node *root1 = NULL;


	isEmpty(root1);
	root1 = insert(root1,5,conversion(count));
	root1 = insert(root1,4,conversion(count));
	root1 = insert(root1,3,conversion(count));
	root1 = insert(root1,2,conversion(count));
	root1 = insert(root1,1,conversion(count));

	root1 = extractMin(root1);
	inorder(root1);

}
