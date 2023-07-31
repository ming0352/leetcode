/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* traversal(TreeNode* root, int val){
        if(root==nullptr){
            return root;
        } 
        if(root->val<val){
            TreeNode* right=traversal(root->right,val);
            if(right==nullptr) root->right=new TreeNode(val);
        }
        if(root->val>val){
            TreeNode* left=traversal(root->left,val);
            if(left==nullptr) root->left=new TreeNode(val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root==nullptr) return new TreeNode(val);
        else return traversal(root,val);

    }
};
// @lc code=end

