/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> qu;
    if (root) qu.push(root);
    while (!qu.empty()) {
      int s = qu.size();
      vector<int> tmp;
      for (int i = 0; i < s; i++) {
        TreeNode* node = qu.front();
        qu.pop();
        tmp.push_back(node->val);
        if (node->left) qu.push(node->left);
        if (node->right) qu.push(node->right);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};
// @lc code=end
