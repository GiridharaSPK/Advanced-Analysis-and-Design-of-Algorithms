// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>//INT_MAX
#include <string.h>
#include <queue>//coz, using BFS
using namespace std;
 
// Number of vertices in given graph
#define V 6
 
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
 
 
bool bfsr(int rGraph[V][V], int s, int t, int parent[],int x)
{
    
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && (rGraph[u][v] >=x || rGraph[v][u] >= x - rGraph[u][v]))
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    
    return (visited[t] == true);
}
 
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t, int actualFlow[V][V])
{
    int u, v;
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities in residual graph
    int rGraph[V][V],rrGraph[V][V]; // Residual graph where rGraph[i][j] indicates 
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)  
    int paths[2*V][V];//to store all the traversed paths        
//     int actualFlow[V][V]; not required -as passeed as an argument
	
	int sat_edges[V][2];//to store saturated edges
	memset(sat_edges, -1 , sizeof(sat_edges));
	
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path to retrace the patth
    int max_flow = 0;  // There is no flow initially
    int iteration=0;
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
    	iteration++;
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            paths[iteration-1][v]=u;//storing all the paths 
            path_flow = min(path_flow, rGraph[u][v]);
        }//now the path_flow is the min capacity of the path 

        // update residual capacities of the edges and reverse edges along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            actualFlow[u][v]+=path_flow;//to show the actual flows
            rGraph[v][u] += path_flow;
        }
        // Add path flow to overall flow
        max_flow += path_flow;
    }
    
    cout << "\nThe maximum possible flow is " << max_flow<<"\n";
    
    //QUESTION 1
    printf("\nQUESTION 1 : \n\nResidual Graph: \n");
    for(u=0;u<V;u++)
    {
		for(v=0;v<V;v++)
        {
//            actualFlow[u][v]= rGraph[u][v];
            printf("%d ", rGraph[u][v]);
        }
        printf("\n");
    }

    printf("\nActual Flows in each edge: \n");
    for(u=0;u<V;u++)
    {
        for(v=0;v<V;v++)
        {
            printf("%d ", actualFlow[u][v]);
        }
        printf("\n");
    }
    
    //QUESTION 1 END
//	int max_inc_path[2*V];//to store the max of each path
//	memset(max_inc_path, 34344 , sizeof(max_inc_path));//initialise with a big number	
	int z,w;
	for(z=0;z<V;z++)
    {
        for(w=0;w<V;w++)
        {
//        	printf("%d\t",rGraph[z][w]);
        	rrGraph[z][w]=rGraph[z][w];
		}
//		printf("\n");
	}
//	printf("\n");
	
	//QUESTION2
	
	int x,opt;
//	do
//	{
		cout<<"\nQUESTION2: \n\nTo increase the max flow by x,\nEnter x :";
		cin>>x;
		if(bfsr(rrGraph, s, t, parent,x))
		{
			printf("\nIncrease the capacitiy of edges as:\n");
			for (v=t; v != s; v=parent[v])
	        {
	            u = parent[v];
	            //printf("(parent,child):(%d,%d)\n",u,v);
	            if(rrGraph[u][v]<x)
	            {
	            	rrGraph[v][u] -= x-rrGraph[u][v];
					printf("(%d -> %d)=%d\n",u,v,x-rrGraph[u][v]);
	            	rrGraph[u][v] += x-rrGraph[u][v];
	            }
				/*else
	            {
	            	rGraph[u][v] -= x;
            		rGraph[v][u] += x;
	            }*/
	        }
	        cout << "\nThe maximum possible flow is " << max_flow+x<<"\n";
		
			cout<<"\nAfter adding "<< x <<" to max flow: \n";
    		for(z=0;z<V;z++)
    		{
        		for(w=0;w<V;w++)
        		{
        			printf("%d ",rrGraph[z][w]);
        			rrGraph[z][w] = rGraph[z][w];
				}
				printf("\n");
			}
		}
		else
		{
			printf("\nNot possible\n");
		}
				
		printf("\n");
//		cout<<"Enter 0 to exit or any other number to continue:";
//		cin>>opt;
//	}while(opt != 0);
	
	//QUESTION2 END
	
    // Return the overall flow
    return max_flow;
}

int main()
{
    int actualFlow[V][V] = 	{ 	{0,0,0,0,0,0},
						  		{0,0,0,0,0,0},
						  		{0,0,0,0,0,0},
						  		{0,0,0,0,0,0},
						  		{0,0,0,0,0,0},
						  		{0,0,0,0,0,0}
							};
    // Let us create a graph shown in the above example
    int graph[V][V] = { {0, 9, 9, 0, 0, 0},
                        {0, 0, 4, 8, 0, 0},
                        {0, 0, 0, 1, 3, 0},
                        {0, 0, 0, 0, 0, 10},
                        {0, 0, 0, 8, 0, 7},
                        {0, 0, 0, 0, 0, 0}
                      };

//    int graph[V][V] = { {0, 16, 13, 0, 0, 0},  geeksforgeeks
//                        {0, 0, 10, 12, 0, 0},
//                        {0, 4, 0, 0, 14, 0},
//                        {0, 0, 9, 0, 0, 20},
//                        {0, 0, 0, 7, 0, 4},
//                        {0, 0, 0, 0, 0, 0}
//                      };
 
//    cout << "\nThe maximum possible flow is " << fordFulkerson(graph, 0, 5, actualFlow);
 		fordFulkerson(graph, 0, 5, actualFlow);
//    int x;
//    printf("\nEnter x,to increase the max flow by x: ");
//    scanf("%d",&x);
//	
//	int paths[V][V];//to store all the traversed paths
//	int max_inc_path[V][2];//to store the max of each path
//	memset(max_inc_path,-1,sizeof(max_inc_path));
		
//    cout << "\nThe maximum possible flow is " << fordFulkerson(graph, 0, 5, actualFlow);   
    return 0;
}

