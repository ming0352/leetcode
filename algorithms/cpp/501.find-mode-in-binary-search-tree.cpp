/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    TreeNode* pre=nullptr;
    vector<int> result;
    int count=0,max_count=0;
    void traversal(TreeNode* cur){
        if (cur==nullptr) return;
        //left
        traversal(cur->left);
        //mid
        if(pre==nullptr) count=1;
        else if(pre->val==cur->val) count++;
        else count=1;
        if(count==max_count) result.emplace_back(cur->val);
        else if(count>max_count){
            max_count=count;
            result.clear();
            result.emplace_back(cur->val);
        }
        pre=cur;
        //right
        traversal(cur->right);
            }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }
};
// @lc code=end

