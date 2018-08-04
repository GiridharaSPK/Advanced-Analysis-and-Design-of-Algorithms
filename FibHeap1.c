#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int num_of_nodes=0;//global variable that stores the number of nodes 
int num_root_list=0;

struct node{
	int key;
	struct node* left;
	struct node* right;
	struct node* parent;
	struct node* child;
	int isMarked;
	int rank;
	int degree;	
};

struct node* min=NULL;//pointer to min


struct node* create_node(int val)
{
	struct node* Node=(struct node*)malloc(sizeof(struct node));
	Node->key=val;//data value of the node
	Node->isMarked=0;//if marked? 1 else 0
	Node->degree=0;//no. of sibling nodes
	Node->rank=0;//no. of child nodes
	Node->left=NULL;//left pointer
	Node->right=NULL;//right pointer
	Node->parent=NULL;//parent pointer
	Node->child=NULL;//child pointer
	printf("\nNode with key %d created\n",Node->key);
	return Node;//retruns the created node to the funtion defined
}

struct node* insert_node(int val)
{
	struct node* Node=create_node(val);//creates a node and returns the created node to Node
	if(num_of_nodes==0)
	{
		Node->right=Node;
		Node->left=Node;
		min=Node;
	}
	else
	{
		Node->left=min->left;
		Node->right=min;
		(min->left)->right=Node;
		min->left=Node;
		//Now check which has low key value and make it min
		if(min->key>Node->key)
		min=Node;
	}
	printf("\nNode with key %d is inserted into heap\n",Node->key);
	num_of_nodes++;//Increase the total number of nodes
	if(Node->parent==NULL) num_root_list+=1; //as the node has no parent, i.e it is root list
	return Node;
}

struct node* insert_child(struct node* node, int val)
{
//	if(node->rank<1)
//	{
		struct node* child_node;
		child_node=create_node(val);//created a node of all NULLs and named child_node
		child_node->left=child_node->right=child_node;//doubly linked list of lenght 1
		child_node->parent=node;//Now child_node is the parent of child_node
		node->rank+=1;//increment rank of the parent	
//	}
	
	if(node->rank==1)//child pointer of the parent is to be pointed to its first child
	node->child= child_node;
	
	if(node->rank>1)//leaving this for now ????
	{
		//join this in the doubly linked list of the previous children at the left of child pointer
//		child_node->left=node->child->left;
//		node->child->left=child_node;
		node->child->left->right=child_node;
		child_node->right=node->child;
		printf("Right of %d is : %d ",child_node->key,node->child->key);
	}
	
	printf("\nNow %d is child of %d \n",(child_node)->key,(node->key));
	
	return child_node;
}

void print_rootList(struct node* node)//prints the root list (doubly linked list)
{
	printf("\nThe root list of the heap is: \n");
	struct node* ptr=node;
	do
	{
		printf("-%d-",ptr->key);
		ptr=ptr->right;
	}while(ptr!=node);
	printf("\n");
}

void print_siblings(struct node* node)
{
	struct node* ptr=node;
	do
	{
		printf("-%d-",ptr->key);
		ptr=ptr->right;
	}while(ptr!=node);
	printf("\n");
}

void free_node(struct node* node)
{
	node->left=NULL;
	node->child=NULL;
	node->right=NULL;
	node->parent=NULL;
	return;
}

void getMin(struct node* node)//get min node in the list of passed node
{
	min=node;
	struct node* ptr=node;
	do
	{
		if ((min->key)>(ptr->key)) 
			min=ptr;
		ptr=ptr->right;
	}
	while(ptr!=node);
//	return min;
}

int extract_min(struct node* node)
{
	int current_min	=node->key;
	if(current_min==NULL) return 0;
	min=node->right;
	printf("temp min: %d\n",min->key);
	
	struct node* ptr=node;
//	node->left=node->right=NULL; Why is this not working here? why should I not free the node/old min which is passed to this function
	
	printf("\nptr is pointing to %d\n",ptr->key);
//	add all the children of min to root list
//	((ptr->child)->right)->left=ptr->left;
//	ptr->left->right=ptr->child->right;
//	printf("\nNow %d 's right sibling is %d\n",ptr->left->key,ptr->child->key);
//	printf("\nptr is pointing to %d\n",ptr->key);

//	ptr->child->right->left=ptr->left;
	if(node->rank!=0)
	{
		ptr->left->right=ptr->child->right;
		printf("\nNow %d is left of %d \n",ptr->left->key,ptr->child->right->key);
	
		((ptr->child)->right)=ptr->right;
		printf("\nNow %d 's right sibling is %d\n",ptr->child->key,ptr->right->key);
//		printf("\nptr is pointing to %d\n",ptr->key);	
	}
	else return -1;//The min doesnt have any children
//	printf("Minimum is %d and is deleted",current_min);
	getMin(min);//new min is stored now in 'min'
	num_root_list=num_root_list-1+ptr->rank;
	return current_min;
}

//void buildRankMatrix()
//{
//	int i=0;
//	int rankMat[num_root_list];
//
//	for(i=0;i<num_root_list;i++)
//	rankMat[i]=NULL;
//	
//	struct node* trav=min;//trav pointer 
//
//	while(trav->right!=min && i==trav->rank && rankMat[i]==NULL)
//	{
//		rankMat[i]=trav;
//		trav=trav->right;
//	}
//	
//	printf("Rank Matrix: ");
//	for(i=0;i<num_root_list;i++)
//	printf(" %d ",rankMat[i]);
//	
//}

void joinAsChild(struct node* node, struct node* AtNode)
{
	node->left->right=node->right;
	node->right->left=node->left;
	node->parent=AtNode;
	if(AtNode->rank==0)
	{
		AtNode->child=node;
	}
	else
	{
		AtNode->child->left->right=node;
		node->right=(AtNode->child);
	}
	num_root_list--;
}

int main()
{
	struct node* root=insert_node(1);
	root=insert_node(3);
	root=insert_node(2);
	root=insert_node(4);
//	root=insert_node(5);
//	root=insert_node(6);
	print_rootList(min);
//printf("\nno. of nodes in root list: %d\n",num_root_list);	

//	printf("%d is left of %d", min->left->key,min->key);
	insert_child(min,10);
	insert_child(min,11);
	//create a random heap
	
//	struct node* child1=(struct node*)malloc(sizeof(struct node));
//	struct node* child2=(struct node*)malloc(sizeof(struct node));
//	child1->key=10;//data value of the node
//	child1->isMarked=0;//if marked? 1 else 0
//	child1->degree=0;//no. of sibling nodes
//	child1->rank=0;//no. of child nodes
//	child1->left=child2;//left pointer
//	child1->right=child2;//right pointer
//	child1->parent=min;//parent pointer
//	child1->child=NULL;//child pointer
//	
//	min->child=child1;
//		
//	child2->key=11;//data value of the node
//	child2->isMarked=0;//if marked? 1 else 0
//	child2->degree=0;//no. of sibling nodes
//	child2->rank=0;//no. of child nodes
//	child2->left=child1;//left pointer
//	child2->right=child1;//right pointer
//	child2->parent=min;//parent pointer
//	child2->child=NULL;//child pointer	
	
//	printf("children of min: %d and %d\n", child1->key,child2->key);
	
//	print_siblings(min->child); //alling this function here has no problems
	printf("\nExtract minimum: %d\n", extract_min(min));
//	printf("\n%d\n",num_root_list);
	print_rootList(min);
	
	//	get the new min
//	printf("\nNew minimum: %d\n",min->key);


//	Fill the rank matrix---------------------------------------
//	buildRankMatrix();
	int i=0;
	struct node* rankMat[num_root_list];

	for(i=0;i<num_root_list;i++)
	rankMat[i]=i;
	
	struct node* trav=min;//trav pointer 
	i=0;
//	FillRankMat:
//		consolidate

	
	while(i<num_root_list)
	{
		if(i!=rankMat[i]->rank)
		{
			while(trav->right!=min && i==trav->rank)
			{
				if(rankMat[i]==i)
				{
					rankMat[i]=trav;
					trav=trav->right;
					i++;
				}
				else
				{
					if (trav->key > rankMat[i]->key)
					{
						//trav join as child at rankMat[i]
						joinAsChild(trav,rankMat[i]);
						trav=min;
					}
					else
					{
						//*rankMat[i] join as child at trav
						joinAsChild(rankMat[i],trav);
						trav=min;
					}
				}
			}
		}
		i++;
	}
	
	printf("Rank Matrix: ");
	for(i=0;i<num_root_list;i++)
	printf(" %d ",rankMat[i]);
	
//  rank matrix is filled--------------------------------------
	
	
	
//-------------------------END OF CODE ALMOST-------------------	
//	printf("\nPress any key to close!!!!!!!!!\n");
//	getchar();
	return 0;
}
//EOC
