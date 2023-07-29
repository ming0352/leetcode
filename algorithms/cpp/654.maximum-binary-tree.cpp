/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node=new TreeNode(nums[0]);
        if(nums.size()==1){
            // node->val=nums[0];
            return node;
        } 
        int max_value=0;
        int max_index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_value){
                max_value=nums[i];
                max_index=i;
            }
        }
        node->val=max_value;
        if(max_index>0){
            vector<int> tmp(nums.begin(),nums.begin()+max_index);
            node->left=constructMaximumBinaryTree(tmp);
        }
        if(max_index<nums.size()-1){
            vector<int> tmp(nums.begin()+max_index+1,nums.end());
            node->right=constructMaximumBinaryTree(tmp);
        }
        return node;
    }
};
// @lc code=end

