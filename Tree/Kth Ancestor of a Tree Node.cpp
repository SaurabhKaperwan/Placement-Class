class TreeAncestor 
{
    public:

        vector<vector<int>> dp;

        TreeAncestor(int n, vector<int>& parent) 
        {
            dp.resize(20, vector<int>(parent.size(), -1));

            //for first ancestor
            for(int i = 0; i < parent.size(); i++)
                dp[0][i] = parent[i];

            for(int i = 1; i < 20; i++)
            {
                for(int j = 0; j < parent.size(); j++)
                {
                    int nodep = dp[i - 1][j];

                    if(nodep != -1)
                        dp[i][j] = dp[i - 1][nodep];
                }
            }   
        }
    
        int getKthAncestor(int node, int k) 
        {
            for(int i = 0; i < 20; i++)
            {
                if(k & (1 << i))
                {
                    node = dp[i][node];
                    if(node == -1)
                        return -1;
                }
            }
            return node;
        }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
