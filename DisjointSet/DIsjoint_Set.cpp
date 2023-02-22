//Used in Dynamic Graphs
//Check whether two nodes belong to same component or not at a any particular time in O(1) using path compression
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
	public:
		vector<int> rank,parent;
		//vector<int> size;

		DisjointSet(int n)
		{
			rank.resize(n+1,0);
			parent.resize(n+1);
			size.resize(n+1,1);
			for (int i = 0; i < n; ++i)
				parent[i] = i;
		}

		int findUParent(int node)
		{
			if(node == parent[node])
				return node;
			//path compression
			return parent[node] = findUParent(parent[node]);	
		}
		void unionByRank(int u,int v)
		{
			int up_u = findUParent(u);
			int up_v = findUParent(v);
			if(up_u == up_v)
				return;
			if(rank[up_u] < rank[up_v])
			{
				parent[up_u] = up_v;
			}
			else if(rank[up_v] < rank[up_u])
			{
				parent[up_v] = up_u;
			}
			else
			{
				parent[up_v] = up_u;
				rank[up_u]++;
			}
		}
/*
		void unionBySize(int u,int v)
		{
			int up_u = findUParent(u);
			int up_v = findUParent(v);


			if(up_u == up_v)
				return;

			if(size[up_u] < size[up_v])
			{
				parent[up_u] = up_v;
				size[up_v] += size[up_u];
			}
			else
			{
				parent[up_v] = up_u;
				size[up_v] += size[up_v];
			}
		}
*/
};

int main()
{
	DisjointSet ds(7);
	ds.unionByRank(1,2);
	ds.unionByRank(2,3);
	ds.unionByRank(4,5);
	ds.unionByRank(6,7);
	ds.unionByRank(5,6);

	if(ds.findUParent(3) == ds.findUParent(7))
		cout<<"Same\n";
	else
		cout<<"Not same\n";

	ds.unionByRank(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) 
        cout << "Same\n";
    else 
    	cout << "Not same\n";

}
