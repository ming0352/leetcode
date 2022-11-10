/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> qu;
    double v;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      double sum = 0.0;
      for (int i = 0; i < size; i++) {
        TreeNode* node = qu.front();
        qu.pop();
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
        sum += node->val;
        if (i == (size - 1)) {
          sum /= size;
          ans.emplace_back(sum);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
