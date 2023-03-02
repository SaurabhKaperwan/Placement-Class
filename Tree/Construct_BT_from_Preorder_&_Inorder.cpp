//Construct Binary Tree from Preorder and Inorder Traversal
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

        TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int inorderStart, int inorderEnd, int preorderStart, int preorderEnd, map<int,int>& mp)
        {
            if(inorderStart > inorderEnd and preorderStart > preorderEnd )
                return NULL;

            TreeNode* node = new TreeNode(preorder[preorderStart]);
            int index = mp[node->val];
            int diff = index - inorderStart;

            node->left = buildTreeUtil(preorder, inorder, inorderStart, index - 1, preorderStart + 1, preorderStart + diff, mp);
            node->right = buildTreeUtil(preorder, inorder, index + 1, inorderEnd, preorderStart + diff + 1, preorderEnd, mp);
            return node;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
        {
            int n = inorder.size();
            int inorderStart = 0, inorderEnd = n - 1;
            int preorderStart = 0, preorderEnd = n - 1;

            map<int,int> mp;

            for(int i = 0; i < n; i++)
            {
                mp[inorder[i]] = i;
            }

            return buildTreeUtil(preorder, inorder, inorderStart, inorderEnd, preorderStart, preorderEnd, mp);
        }
};
