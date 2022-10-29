/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    long int m = LONG_MIN;
    bool isValidBST(TreeNode *root) {
        bool ans = false;
        if (root == nullptr)
            return true;
        ans = isValidBST(root->left);
        if (root->val > m) {
            m = root->val;
        } else {
            return false;
        }
        return ans && isValidBST(root->right);
    }
};
// @lc code=end
