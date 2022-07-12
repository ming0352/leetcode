/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int m=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j++];
            while(target<=sum){
                m=min(j-i,m);
                sum-=nums[i++];
            }
        }
        
        return m==INT_MAX?0:m;
    }
};
// @lc code=end

