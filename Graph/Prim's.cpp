class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//TC:O(E log E)
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //first : weight and second : node
        priority_queue< tuple<int,int>,
        vector<tuple<int,int>>,
        greater<tuple<int,int>>
        > pq;
        vector<int> visited(V,0);
        pq.push(make_tuple(0,0));
        int sum = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int wt = get<0>(it);
            int node = get<1>(it);
            pq.pop();
            if(visited[node] == 1)
                continue;
            //adding to mst
            sum += wt;
            visited[node] = 1;
            for(auto itr : adj[node])
            {
                pq.push(make_tuple(itr[1], itr[0]));
            }
        }
        return sum;
    }
};
