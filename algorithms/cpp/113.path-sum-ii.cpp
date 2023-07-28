/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(TreeNode *root, int targetSum) {
        if (!root->left && !root->right && targetSum == 0) {
            ans.push_back(path);
            return;
        }
        if (!root->left && !root->right) {
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            traversal(root->left, targetSum - root->left->val);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            traversal(root->right, targetSum - root->right->val);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        ans.clear();
        path.clear();
        if (!root)
            return ans;
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return ans;
    }
};
// @lc code=end
