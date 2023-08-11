/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void backtracking(vector<int>& nums,vector<bool> used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return; 
        }
        unordered_set<int> uset;
        for(int i=0;i<nums.size();i++){
            if((!path.empty()&&used[i])|| uset.find(nums[i])!=uset.end()) continue;
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums,used);
            path.pop_back();
            used[i]=false;
            uset.insert(nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backtracking(nums,used);
        return result;
    }
};
// @lc code=end

