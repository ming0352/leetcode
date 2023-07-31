/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode *traversal(TreeNode *root, int key) {
        if (root == nullptr)
            return root;

        if (root->val == key) {
            if (root->left == nullptr) {
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            } else if (root->right == nullptr) {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            } else if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else {
                TreeNode *cur = root->right;
                while (cur->left != nullptr)
                    cur = cur->left;
                cur->left = root->left;
                TreeNode *tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if (root->val > key) {
            TreeNode *left = traversal(root->left, key);
            root->left = left;
        }
        if (root->val < key) {
            TreeNode *right = traversal(root->right, key);
            root->right = right;
        }
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key) {
        return traversal(root, key);
    }
};
// @lc code=end
