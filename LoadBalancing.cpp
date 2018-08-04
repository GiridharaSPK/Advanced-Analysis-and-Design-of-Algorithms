#include<iostream>
#include<cstring>

using namespace std;

void printArray(int n, int* Array)
{
  int i=0;
  for(i=0;i<n;i++)
  cout<<Array[i];
}

// void LoadBalance(int n, int m, int Assignment[][10], int* TaskLoads)
// {
//   int i=0,j=0;
//   for(i=0;i<m;i++)
//   {
//     for(j=0;j<n;j++)
//     {
//       if(j<m)//for first m tasks assign to m machines
//       Assignment[i][j]=TaskLoads[i];
//       else
//       {
//         //check least value in the array and assign(TaskLoads[i]) to it
//       }
//     }
//   }
// }
int getleastind(int* Array)
{
  int i=-1;
  int min=INT_MAX;
  for(;i<Array.length;i++){
    if(min<Array[i])
      
  }
  return i;
}

void LoadBalance(int n, int m, int* Assignment, int* TaskLoads)
{
  int i,j;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(j<m){//for first m tasks assign to m machines
        Assignment[j]=TaskLoads[i];
      }else{
        //check least value in the array and assign(TaskLoads[i]) to it
        //TaskLoads[getleastind];
      }
    }
  }
}

int main()
{
  int n=10;//n-number of tasks
  int m=4;//m- number of machines
  int TaskLoads[n]={1,2,3,4,5,6,7,8,9,100};
  int Assignment[n];//machine to task: A[1]-task1 is assinged 2nd machine
  memset(Assignment,0,sizeof(Assignment));
  LoadBalance(n,m,Assignment,TaskLoads);
  printArray(n,TaskLoads);
}
