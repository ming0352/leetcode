/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int getleft(TreeNode *node, int &sum) {
        if (node->left == nullptr && node->right == nullptr)
            return 0;
        if (node->left) {
            getleft(node->left, sum);
        }
        if (node->right) {
            getleft(node->right, sum);
        }
        if (node->left && node->left->left == nullptr &&
            node->left->right == nullptr) {
            sum += node->left->val;
        }

        return sum;
    }
    int sumOfLeftLeaves(TreeNode *root) {
        int sum = 0;
        return getleft(root, sum);
    }
};
// @lc code=end
