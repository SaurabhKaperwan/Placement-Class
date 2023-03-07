//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector<int> parent;
    
    
    int findUParent(int node)
    {
        if(node == parent[node])
            return node;
        return findUParent(parent[node]);
    }
    
    void unionSet(int u, int v)
    {
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        parent[up_v] = up_u;
    }
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        parent.resize(V);
        for(int i = 0; i < V; i++)
            parent[i] = i;
        
        vector< tuple<int, int, int> > edges;
        
        for(int i = 0; i < V; i++)
        {
            for(auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];
                edges.push_back(make_tuple(wt, u, v));
            }
        }
           
        sort(edges.begin(), edges.end());
        int sum = 0;
        
        for(auto it : edges)
        {
            int wt = get<0>(it);
            int u = get<1>(it);
            int v = get<2>(it);
            
            if(findUParent(u) != findUParent(v))
            {
                sum += wt;
                unionSet(u, v);
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
