/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
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
/*
//方法一
class Solution
{
public:
    vector<int> preorder;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            preorder.emplace_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return preorder;
    }
};*/
//方法二
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ans;
        if (root == nullptr)
            return ans;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.emplace_back(node->val);
            if (node->right)
            {
                st.push(node->right);
            }
            if (node->left)
            {
                st.push(node->left);
            }
        }
        return ans;
    }
};
// @lc code=end
