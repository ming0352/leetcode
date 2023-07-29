/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *traversal(TreeNode *cur, TreeNode *p, TreeNode *q) {
        if (cur == q || cur == p || cur == nullptr)
            return cur;
        // left
        TreeNode *left = traversal(cur->left, p, q);
        // right
        TreeNode *right = traversal(cur->right, p, q);
        // mid
        if (right != nullptr && left != nullptr)
            return cur;
        if (right == nullptr && left != nullptr)
            return left;
        else if (right != nullptr && left == nullptr)
            return right;
        else
            return nullptr;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        return traversal(root, p, q);
    }
};
// @lc code=end
