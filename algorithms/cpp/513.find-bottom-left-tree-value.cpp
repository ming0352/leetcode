/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int maxDepth = INT_MIN, val;
    void getHeight(TreeNode *node, int depth) {
        if (node->left == nullptr && node->right == nullptr) {
            if (maxDepth < depth) {
                maxDepth = depth;
                val = node->val;
                return;
            }
        }
            if (node->left) {
                depth += 1;
                getHeight(node->left, depth);
                depth -= 1;
            }
            if (node->right) {
                depth += 1;
                getHeight(node->right, depth);
                depth -= 1;
            }
        return;
    }
    int findBottomLeftValue(TreeNode *root) {
        getHeight(root, 0);
        return val;
    }
};
// @lc code=end
