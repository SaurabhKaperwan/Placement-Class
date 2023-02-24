//https://leetcode.com/problems/critical-connections-in-a-network/description/
//Bridges:Those Edges are called bridge in whose removal the graph is broken in two or more number of componenets.
//tin[] : insetion time of  a node
//low[] : the lowest time of insertion of all adjacent nodes apart from parent
class Solution 
{
    public:
        int timer = 1;

        void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], int tin[], int low[],vector<vector<int>> &bridges)
        {
            visited[node] = 1;
            tin[node] = low[node] = timer;
            timer++;
            for(auto it : adj[node])
            {
                if(it == parent)
                    continue;
                else if(!visited[it])
                {
                    dfs(it,node,visited,adj,tin,low,bridges);
                    low[node] = min(low[node], low[it]);
                    if(low[it] > tin[node])
                        bridges.push_back({it,node});
                }
                else
                    low[node] = min(low[node], low[it]);

            }
        }

        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
        {
            vector<int> adj[n];
            for(auto it : connections)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }

            vector<int> visited(n,0);
            int tin[n];
            int low[n];
            vector<vector<int>> bridges;
            dfs(0,-1,visited,adj,tin,low,bridges);
            return bridges;

        }
};
