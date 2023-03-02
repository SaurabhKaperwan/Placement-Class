//https://leetcode.com/problems/predict-the-winner/
class Solution 
{
    public:

        int predictUtil(vector<int>& nums, int i, int j, vector<vector<int>>& dp)
        {
            if(i == j)
                return nums[i];
            if(dp[i][j] != -1)
                return dp[i][j];
            int st = nums[i] - predictUtil(nums, i + 1, j, dp);
            int lt = nums[j] - predictUtil(nums, i, j-1, dp);
            return dp[i][j] = max(st, lt);
        }

        bool PredictTheWinner(vector<int>& nums) 
        {
            int n = nums.size();
            vector<vector<int>> dp(n,vector<int>(n,-1));
            int i = 0, j = n - 1;
            return predictUtil(nums, i, j, dp) >= 0;
        }
};
