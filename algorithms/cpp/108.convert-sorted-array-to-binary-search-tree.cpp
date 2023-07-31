/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode *traversal(vector<int> &nums, int left, int right) {
        //左閉右閉
        if (left>right) 
            return nullptr;
        int mid = (left + right) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);

        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
