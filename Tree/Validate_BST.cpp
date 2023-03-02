//https://leetcode.com/problems/validate-binary-search-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
        bool isValidBSTUtil(TreeNode* root, long rangeStart,long rangeEnd)
        {
            if(root == NULL)
                return true;
            if(root->val >= rangeEnd || root->val <= rangeStart)
                return false;
            bool left = isValidBSTUtil(root->left, rangeStart, root->val);
            bool right = isValidBSTUtil(root->right, root->val, rangeEnd);
            return (left && right);
        }
        bool isValidBST(TreeNode* root) 
        {
            long rangeStart = LONG_MIN;
            long rangeEnd = LONG_MAX;

            return isValidBSTUtil(root, rangeStart, rangeEnd);
        }
};
