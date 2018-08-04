#include<iostream>

using namespace std;

void printArray(int array[]);
int push(int array[], int p);
int checkTurns(int array[],int i);

int main()
{
	int array[]={2,3,5,4,12,6,4,23,34};
	int i=0,j=0,n=sizeof(array)/sizeof(array[0]);
	int turns[n];
	for(i=0;i<n;i++)
	{
		i=checkTurns(array, i);
		push(turns,i);
	}
	printArray(turns);
}

int checkTurns(int array[],int i)
{
	if(array[i]<=array[i+1])
	while(array[i]<=array[i+1])
	i++;
	else
	while(array[i]>array[i+1])
	i++;
	return i;
}

void printArray(int array[])
{
	for (int i=0;array[i]!='\0';i++)
	printf("%d ",array[i]);
}

int push(int array[],int p)
{
	for(int i=0;array[i]!='\0';i++)
	array[i+1]=p;
}
