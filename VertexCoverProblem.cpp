#include<iostream>
#define N 4

using namespace std;

void VertexCoverProblem(int Adj[N][N])
{
  bool visited[N];
  for (int i=0; i<N; i++)
      visited[i] = false;

  for (int u=0; u<N; u++)
  {
    if (visited[u] == false)
    {
      for (int i= 0; Adj[u][i] == 1 && i<N; ++i)
      {
        int v = i;
        if (visited[v] == false)
        {
         visited[v] = true;
         visited[u]  = true;
         break;
        }
      }
    }
  }
  for (int i=0; i<N; i++)
      if (visited[i])
        cout << i << " ";
}

int main()
{
//  int Adj[N][N] = { {0,1,1,0,0,0,0},
//              {0,0,0,1,0,0,0},
//              {0,0,0,0,0,0,0},
//              {0,0,0,0,1,0,0},
//              {0,0,0,0,1,0,0},
//              {0,0,0,0,0,1,0},
//              {0,0,0,0,0,0,0}
//            };

	int Adj[N][N]=	{	{0,1,1,1},
						{1,0,1,0},
						{0,1,0,1},
						{1,0,1,0}
					};
	
  VertexCoverProblem(Adj);
}
