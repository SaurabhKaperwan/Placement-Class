//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
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

        TreeNode* buildTreeUtil(vector<int>& postorder, vector<int>& inorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map<int,int>& ump)
        {
            if(inorderStart > inorderEnd and postorderStart > postorderEnd )
                return NULL;

            TreeNode* node = new TreeNode(postorder[postorderEnd]);
            int index = ump[node->val];
            int diff = index - inorderStart;

            node->left = buildTreeUtil(postorder, inorder, inorderStart, index - 1, postorderStart, postorderStart + diff -1, ump);
            node->right = buildTreeUtil(postorder, inorder, index + 1, inorderEnd, postorderStart + diff, postorderEnd-1, ump);
            return node;
        }

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
        {
            int n = inorder.size();
            int inorderStart = 0, inorderEnd = n - 1;
            int postorderStart = 0, postorderEnd = n - 1;

            unordered_map<int,int> ump;

            for(int i = 0; i < n; i++)
            {
                ump[inorder[i]] = i;
            }

            return buildTreeUtil(postorder, inorder, inorderStart, inorderEnd, postorderStart, postorderEnd, ump);
        }
};
