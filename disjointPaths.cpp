// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>//INT_MAX
#include <string.h>
#include <queue>//coz, using BFS
using namespace std;
 
// Number of vertices in given graph
#define n 3
#define V 2*n+2
 
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));//initialise the array with zeros //needs string.h 
 
    // Create a queue, enqueue source vertex and mark source vertex as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return true, else false
    return (visited[t] == true);
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities in residual graph
    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates 
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)  
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path to retrace the patth
 
    int max_flow = 0;  // There is no flow initially
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }//now the path_flow is the min capacity of the path 
 
        // update residual capacities of the edges and reverse edges along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
 
// Driver program to test above functions
int main()
{
    // Let us create a graph shown in the above example
    //G is initial graph
				//	 1` 2` 3` 
 	int G[n][n]={	{1, 0, 0},
					{1, 0, 0},
					{0, 1, 0}
	 			};

	int graph[V][V];//has sink and terminal
	int i=0,j=0;
	
	for(i=0;i<V;i++)//zero matrix
	{
		for(j=0;j<V;j++)
		{
			graph[i][j]=0;
		}
	}
	
	i=0;//source to n nodes
	for(j=1;j<n+1;j++)
	{
		graph[i][j]=1;	
	}
	
	j=2*n+1;//n nodes to terminal
	for(i=n+1;i<2*n+1;i++)
	{
		graph[i][j]=1;
	}
	
	//copy G to graph
	for(i=1;i<n+1;i++)
	{
		for(j=n+1;j<2*n+1;j++)
		{
			graph[i][j]=G[i-1][j-n-1];
		}
	}	

//		 			//   s  1  2  3  1` 2` 3` t 
//    int graph[V][V] = { {0, 1, 1, 1, 0, 0, 0, 0},
//                        {0, 0, 0, 0, 1, 0, 0, 0},
//                        {0, 0, 0, 0, 1, 0, 0, 0},//	 	1 -	1`
//                        {0, 0, 0, 0, 0, 1 ,0, 0},// s/-\  2 /	2`/-\t
//                        {0, 0, 0, 0, 0, 0, 0, 1},//		3 / 3`
//                        {0, 0, 0, 0, 0, 0, 0, 1},
//                        {0, 0, 0, 0, 0, 0, 0, 1},
//                        {0, 0, 0, 0, 0, 0, 0, 0}
//                      };

//    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
 		cout << "The number of disjoint paths : " << fordFulkerson(graph, 0, V-1);
    return 0;
}

