#include<stdio.h>

void display(int);
void show(int, int);

int main()
{
	int i=10, j=20, k=0;
	
	display(i);
	show(i, j);
	return 0;
	
}

void display(int c, int d)
{
	printf("%d %d\n",c,d);
}

void show(int c)
{
	printf("%d\n",c);
}
