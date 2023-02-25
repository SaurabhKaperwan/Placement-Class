//It is a node in whose removal the graph breaks down into two or more components
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
  private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &tm, vector<int> &low, vector<int> &ans)
    {
        visited[node] = 1;
        low[node] = tm[node] = timer;
        timer++;
        int child = 0;
        
        for(auto it : adj[node])
        {
            if(it == parent)
                continue;
            
            if(!visited[it])
            {
                dfs(it, node, adj, visited, tm, low, ans);
                low[node] = min(low[it], low[node]);
                if(low[it] >= tm[node] and parent != -1)
                {
                    ans.push_back(node);
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tm[it]);
            }
        }
        if(child > 1 and parent == -1)
            ans.push_back(node);
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) 
    {
        vector<int> visited(V,0);
        vector<int> tm(V);
        vector<int> low(V);
        vector<int> ans;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                dfs(0, -1, adj, visited, tm, low, ans);
            }
        }
        set<int> s(ans.begin(), ans.end());
        ans.assign(s.begin(), s.end());
        
        if(!ans.size())
            return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
