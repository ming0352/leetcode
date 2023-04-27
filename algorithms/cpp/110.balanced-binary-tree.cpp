/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    int getHeight(TreeNode *node, int height) {
        if (node == nullptr) {
            return 0;
        }
        int left_height = getHeight(node->left, height);
        if (left_height == -1)
            return -1;
        int right_height = getHeight(node->right, height);
        if (right_height == -1)
            return -1;
        return abs(left_height - right_height) > 1
                   ? -1
                   : 1 + max(left_height, right_height);
    }
    bool isBalanced(TreeNode *root) {
        int x = getHeight(root, 0);
        return x == -1 ? false : true;
    }
};
// @lc code=end
