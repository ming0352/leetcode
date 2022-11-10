/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    stack<vector<int>> st;
    queue<TreeNode*> qu;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      vector<int> tmp;
      for (int i = 0; i < size; i++) {
        TreeNode* node = qu.front();
        qu.pop();
        tmp.emplace_back(node->val);
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
      }
      st.push(tmp);
    }
    while (!st.empty()) {
      ans.emplace_back(st.top());
      st.pop();
    }
    return ans;
  }
};
// @lc code=end
