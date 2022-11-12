/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
  bool compare(TreeNode* left, TreeNode* right) {
    bool same=false;
    if ((left == nullptr && right != nullptr) ||
        (left != nullptr && right == nullptr)) {
      return false;
    } else if (left == nullptr && right == nullptr) {
      return true;
    } else if (left->val == right->val) {
      same =compare(left->left, right->right) &&
             compare(left->right, right->left);
    } else if (left->val != right->val) {
      return false;
    }
    return same;
  }
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }

    return compare(root->left, root->right);
  }
};
// @lc code=end
