//https://www.codechef.com/problems/REVERSE?tab=statement
#include<bits/stdc++.h>
using namespace std;

int zeroOneBFS(vector<pair<int,int>> adj[], int src, int V)
{
    queue<int> q;
    q.push(src);
    vector<int> level(V,INT_MAX);
    level[src] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            if( level[adj[u][i].first] > level[u] + adj[u][i].second )
            {
                level[adj[u][i].first] = level[u] + adj[u][i].second;
                q.push(adj[u][i].first);
            }
        }
    }
    return level[V-1] == INT_MAX ? -1 : level[V-1];
}

int main()
{
    int V,E;
    cin>>V>>E;
    
    vector< pair<int,int> > adj[V+1];
    
    for(int i = 0; i < E; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    
    cout<<zeroOneBFS(adj,1,V+1);
}
