/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode *root) {
        queue<TreeNode *> qu;
        int count = 0;
        if (root == nullptr) {
            return qu.size();
        } else if (root->left == nullptr && root->right == nullptr) {
            return 1;
        } else {
            qu.push(root);
            while (!qu.empty()) {
                TreeNode *tmp = qu.front();
                qu.pop();
                count++;
                if (tmp->left != nullptr) {
                    qu.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    qu.push(tmp->right);
                }
            }
            return count;
        }
    }
};
// @lc code=end
