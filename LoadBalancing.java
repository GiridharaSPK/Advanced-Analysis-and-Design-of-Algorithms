import java.util.*;

class LoadBalance{
  public static void printArray(int Array[])
  {
    int i;
    for(i=0;i<Array.length;i++)
      System.out.println(Array[i]);
  }
  public static void LoadBalance(int n, int m, int Assignment[][], int TaskLoads[])
  {
    int i=0,j=0;
    for(i=0;i<m;i++){
      for(j=0;j<n;j++){
        if(j<m)//for first m tasks assign to m machines
        Assignment[i][j]=TaskLoads[i];
        else
        {
        //check least value in the array and assign(TaskLoads[i]) to it
        }
      }
    }
  }

  public static void main(String args[])
  {
    int n=10;//n-number of tasks
    int m=4;//m- number of machines
    int [] TaskLoads = {1,2,3,4,5,6,7,8,9,100};
    int [][] Assignment = new int[n][m];
    Arrays.fill(Assignment, 0);
    // task to machine : A[1][2]-machine1 is assinged 2nd time
    LoadBalance(n,m,Assignment,TaskLoads);
    printArray(Assignment[0]);
  }
}
