/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return nullptr;
        if (root->val < p->val && root->val < q->val) {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right!=nullptr)
                return right;
        }
        if (root->val > p->val && root->val > q->val) {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (right!=nullptr)
                return left;
        }
            return root;

    }
};
// @lc code=end
