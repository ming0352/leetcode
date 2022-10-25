/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorder;
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            postorder.emplace_back(root->val);
        }
        return postorder;
    }
};*/
//方法二
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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
            if (node->left)
            {
                st.push(node->left);
            }
            if (node->right)
            {
                st.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
