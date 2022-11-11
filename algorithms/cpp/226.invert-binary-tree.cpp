/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
  TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> qu;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      for (int i = 0; i < size; i++) {
        TreeNode *node = qu.front(), *tmp = nullptr;
        qu.pop();
        tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
      }
    }
    return root;
  }
};
// @lc code=end
