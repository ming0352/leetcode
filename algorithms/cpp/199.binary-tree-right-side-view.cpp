/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> qu;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = qu.front();
        qu.pop();
        if (i == size - 1) {
          ans.emplace_back(node->val);
        }
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
