/*
	TC : O(N log k)
	N = total no. of elements
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &arrays)
{
	int k = arrays.size();

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

	vector<int> ans;

	//Add first element of each array

	for(int i = 0; i < k; i++)
	{
		if(!arrays[i].empty())
			minHeap.push({arrays[i][0], i});
	}

	while(!minHeap.empty())
	{
		auto top = minHeap.top();
		minHeap.pop();

		int value = top.first;
		int arrayIndex = top.second;
		ans.push_back(value);

		//If there are more elements in the same array then add the next element from that array
		
		if(arrays[arrayIndex].size() > 1)
		{
			arrays[arrayIndex].erase(arrays[arrayIndex].begin());
			minHeap.push({arrays[arrayIndex][0], arrayIndex});
		}		
	}
	return ans;
}

int main()
{
	vector<vector<int>> arrays = {{1, 3, 5}, {2, 4, 6}, {0, 7, 8, 9}};
	
	vector<int> ans = mergeKSortedArrays(arrays);	

	cout<<"Merged array:\n";

	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
