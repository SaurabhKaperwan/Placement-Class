/* If weight of all edges is 0 or 1 then we can find shortest distance from source node to all other nodes*/
//TC : O(V+E)
#include <bits/stdc++.h>
using namespace std;

void insertEdge(vector <pair<int,int>> adj[], int u, int v,int w) 
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

vector<int> zeroOneBFS(vector<pair<int,int>> adj[],int V,int src)
{
	deque<int> deq;
	vector<int> dist(V,INT_MAX);
	deq.push_back(src);

	dist[src] = 0;

	while(!deq.empty())
	{
		int u = deq.front();
		deq.pop_front();
		for(auto it : adj[u])
		{
			if(dist[it.first] > dist[u] + it.second)
			{
				dist[it.first] = dist[u] + it.second;

				if(it.second == 0)
					deq.push_front(it.first);
				else
					deq.push_back(it.first);
			}
		}
	}
	return dist;
}

int main()
{
	vector<pair<int,int>> adj[6];
	insertEdge(adj,0, 1, 0);
  	insertEdge(adj,0, 2, 1);
  	insertEdge(adj,1, 3, 1);
  	insertEdge(adj,3, 4, 0);
  	insertEdge(adj,4, 5, 1);
  	insertEdge(adj,5, 2, 1);
    vector<int> dist = zeroOneBFS(adj,6,0);
     for (int i = 0; i < 6; i++)
      	cout << "Distance from the source node to " << i << ":" << "\t" << dist[i] << endl;
}
