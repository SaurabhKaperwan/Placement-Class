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
class Solution 
{
    public:

        TreeNode* buildTreeUtil(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp)
        {
            if(preStart > preEnd || inStart > inEnd)
                return NULL;
            
            TreeNode* root = new TreeNode(preorder[preStart]);
            int ele = mp[root->val];
            int nEle = ele - inStart;

            root -> left = buildTreeUtil(preorder, preStart + 1, preStart + nEle, inorder, inStart, ele - 1, mp);

            root -> right = buildTreeUtil(preorder, preStart + nEle + 1, preEnd, inorder, ele + 1, inEnd, mp);
            return root;
        }

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
        {
            int preStart = 0, preEnd = preorder.size() - 1;
            int inStart = 0, inEnd = inorder.size() - 1;

            map<int,int> mp;

            for(int i = inStart; i <= inEnd; i++)
                mp[inorder[i]] = i;
            return buildTreeUtil(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
        }
};
