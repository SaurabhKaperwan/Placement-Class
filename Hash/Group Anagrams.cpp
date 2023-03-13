/*
  TC : O(N * M log M)
  where N is the number of strings in the input array and M is the maximum length of a string in the array
*/
class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<int>> anagramMap;
        vector<vector<string>> ans;

        for(int i = 0; i < strs.size(); i++)
        {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(i);
        }
        for(auto &it : anagramMap)
        {
            vector<int>& indices = it.second;
            vector<string> temp;
            for(int i = 0; i < indices.size(); i++)
            {
                temp.push_back(strs[indices[i]]);
            }
            ans.push_back(temp);
        }
        return ans;    
    }
};
