/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
//方法一
/*class Solution
{
public:
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            inorderTraversal(root->left);
            inorder.emplace_back(root->val);
            inorderTraversal(root->right);
        }
        return inorder;
    }
};*/
//方法二
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty())
        {
            if (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();
                ans.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end
