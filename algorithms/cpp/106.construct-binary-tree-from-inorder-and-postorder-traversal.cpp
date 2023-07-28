/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        int rootval = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootval);
        if (postorder.size() == 1)
            return root;
        int splitindex = 0;
        for (; splitindex < inorder.size(); splitindex++) {
            if (inorder[splitindex] == root->val) {
                break;
            }
        }
        vector<int> leftinorder(inorder.begin(), inorder.begin() + splitindex);
        vector<int> rightinorder(inorder.begin() + splitindex + 1,
                                 inorder.end());
        postorder.resize(postorder.size() - 1);
        vector<int> leftpostorder(postorder.begin(),
                                  postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size(),
                                   postorder.end());

        root->left = traversal(leftinorder, leftpostorder);
        root->right = traversal(rightinorder, rightpostorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 && postorder.size() == 0)
            return nullptr;
        return traversal(inorder, postorder);
    }
};
// @lc code=end
