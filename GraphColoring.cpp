#include <iostream>
#define N 4
using namespace std;

// int A[N][N]={ {0,1,1,1}, {1,0,0,0}, {1,0,0,0},{1,0,0,0}  };
int A[N][N]={ {0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0}};
int soln[N];//={-1,-1,-1,-1};
int chi=0;//number of colors needed
int count=0;//count_th node

bool check(int A[N][N],int chi, int count, int i){//check for the adjacent nodes if ith color is there
  for(int j=0;j<N;j++){
    if(A[count][j]==1){//adjecent node
	  if(soln[j]==i)//of color not i
      	return false;//can color
	}
  }
  return true;
}

bool color(int A[N][N], int chi, int count){//checks if we can color all the nodes with chi colors
  if(count>=N){
    return true;
  }
  for(int i=1;i<=chi;i++){//ith color upto chi colors
    if(check(A,chi,count,i)){//check on count node if count_th node, is adjacent to some node of i_th color
      soln[count]=i;
      return color(A,chi,count+1);//after count_th node, color the count+1_th node
    }
  }
  return false;//cannot color with chi colors
}

int main(){
  for(int i=0;i<N;i++){//initally all colors zero
  	soln[i]=-1;	
  }
  soln[0]=0;
  for(chi=1;chi<=N;chi++){
    if(color(A,chi,count)){//if we can color with chi colors, break
      break;
    }
  }
  cout<<"Graph: "<<endl;//adjacency matrix
  for(int j=0;j<N;j++){
    for(int k=0;k<N;k++){
      cout<<A[j][k]<<"\t";
    }
    cout<<" "<<endl;
  }
  cout<<"Color solution: "<<endl;
  for(int k=0;k<N;k++)
  cout<<soln[k]<<"\t";
}
