/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> qu;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int max = INT_MIN;
      int size = qu.size();
      for (int i = 0; i < size; i++) {
        TreeNode* node = qu.front();
        qu.pop();
        if (node->val > max) {
          max = node->val;
        }
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
      }
      ans.emplace_back(max);
    }
    return ans;
  }
};
// @lc code=end
