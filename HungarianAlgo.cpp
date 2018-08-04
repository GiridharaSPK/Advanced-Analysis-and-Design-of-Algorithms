#include <iostream>
#include <limits.h>
#define n 4

int getMinCost(int matrix[n][n])
{
  int cost=0,i=0,j=0;
  int min =INT_MAX;
  int rowIndex=0;colIndex=0;
  //step1
  //substract the smallest of every row from each element of the row
  for(j=0;j<n;j++)
  {
    for(i=0;i<n;i++)
    {
      if(inputArray[j][i]<min)
      {
        min=inputArray[j][i];
        // colIndex=i;//ith index is minimum element for s
      }
    }
    for(i=0;i<n;i++)
    {
      matrix[j][i]-=min;
    }
  }
  //step2
  min=INT_MAX;
  // for(int i=0;i<n;i++)
  // {
  //   if(inputArray[i][colIndex]<min){
  //     min=inputArray[i][colIndex];
  //     rowIndex=i;
  //   }
  // }
  for(j=0;j<n;j++)
  {
    for(i=0;i<n;i++)
    {
      if(inputArray[i][j]<min)
      {
        min=inputArray[i][j];
        // colIndex=i;//ith index is minimum element for s
      }
    }
    for(i=0;i<n;i++)
    {
      matrix[i][j]-=min;
    }
  }

  return cost;
}


int main()
{
  int i=0,j=0;
  cost_matrix[n][n]={ {9,2,7,8},
		                  {6,4,3,7},
		                  {5,8,1,8},
		                  {7,6,9,4}
                    };

    cout<<("The minimum cost is: ")<<getMinCost(cost_matrix)<<"\n";
}
