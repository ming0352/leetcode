/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
    int result = INT_MAX;
    TreeNode *pre = nullptr;
    void traversal(TreeNode *cur) {
        if (cur == nullptr)
            return;
        // 左
        traversal(cur->left);
        // 中
        if (pre) {
            result=min(result,cur->val-pre->val);
        }
        pre=cur;
        // 右
        traversal(cur->right);
    }
    int getMinimumDifference(TreeNode *root) { 
        traversal(root);
        return result;
         }
};
// @lc code=end
