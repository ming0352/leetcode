/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    void traversal(TreeNode *node, vector<int> &path, vector<string> &ans) {
        string s = "";
        if (node == nullptr)
            return;
        else
            path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            for (int i = 0; i < path.size() - 1; i++) {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(node->val);
            ans.push_back(s);
            return;
        }
        if (node->left) {
            traversal(node->left, path, ans);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, ans);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        vector<int> path;
        traversal(root, path, ans);
        return ans;
    }
};
// @lc code=end
