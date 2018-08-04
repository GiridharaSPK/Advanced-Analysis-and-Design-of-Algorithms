#include<iostream>

using namespace std;

long int fact(int);
int ncr(int,int);
int fun(int ,int []);
int maxSum(int [], int);

int i=0,j=0,k=0,l=0,N,T;
int count=0;

int main(){
	cin>>T;
	float sol[T];
	for(i=0;i<T;i++){
		cin>>N;
		int ar[N];
		for(j=0;j<N;j++){
			cin>>ar[j];
		}
		int max=0;
		count=0;
		for(k=N-1;k>=0;k--){
			for(l=0;l<k;l++){
				if((ar[k]+ar[l])==maxSum(ar,N))
					count++;
			}
		}
		if(N>2)
		sol[i]=(float)count/(float)ncr(N,2);
		else if (N<=2)
		sol[i]=1;
	}
	
	for(i=0;i<T;i++)
	printf("%f\n",sol[i]);
	
	return 0;
}

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n)
{
    // k must be greater
    if (n < 2)
       return arr[0];
 
 	if (n==2)
	 	return arr[0]+arr[1];
    // Compute sum of first window of size k
    int res = 0;
    for (int i=0; i<2; i++)
       res += arr[i];
 
    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of 
    // current window.
    int curr_sum = res;
    for (int i=2; i<n; i++)
    {
       curr_sum += arr[i] - arr[i-2];
       res = max(res, curr_sum);
    }
 
    return res;
}

int ncr(int n, int r){
	return (fact(n))/(fact(r)*fact(n-r));
}

long int fact(int x)          //defining the function or function definition
{
	int i, f=1;
	for(i=2; i<=x; i++)
	{
		f=f*i;
	}
	return f;
}
