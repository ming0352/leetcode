/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool getsum(TreeNode *root, int count) {
        if (!root->left && !root->right && count == 0) {
            return true;
        }
        if (!root->left && !root->right) {
            return false;
        }
        if (root->left) {
            if (getsum(root->left, count - root->left->val))
                return true;
        }
        if (root->right) {
            if (getsum(root->right, count - root->right->val))
                return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root)
            return false;
        return getsum(root, targetSum - root->val);
    }
};
// @lc code=end
