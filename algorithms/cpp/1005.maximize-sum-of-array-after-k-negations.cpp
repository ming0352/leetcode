/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start
class Solution {
  public:
  static bool cmp(int a,int b){
    return abs(a)>abs(b);
  }
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int sum = 0;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            if(k>0 && nums[i]<0){
                nums[i] *= -1;
                k--;
            }
        }
        if(k % 2==1) nums[nums.size()-1]*= -1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
        }
        return sum;
    }
};
// @lc code=end
