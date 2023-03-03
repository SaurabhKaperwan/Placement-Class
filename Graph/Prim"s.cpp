//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//TC:O(E log E)
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //first : weight and second : node
        priority_queue< pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;
        vector<int> visited(V,0);
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if(visited[node] == 1)
                continue;
            //adding to mst
            sum += wt;
            visited[node] = 1;
            for(auto itr : adj[node])
            {
                pq.push({itr[1], itr[0]});
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
