/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */
//解題思路
//1.首先創一個一樣大小的陣列
//2.因為左右兩邊的數平方後一定比中間的大，故使用雙指針的方式來比較平方後的大小，並依序加入新的陣列
//3.最後得到平方後且由小到大排序的新陣列
//
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        ans.resize(nums.size());
        int i=0,j=nums.size()-1,k=nums.size()-1;
        for(;i<=j;)
        {

            if(nums[i] * nums[i]>nums[j] * nums[j]){
                ans[k--]=nums[i]*nums[i];
                i++;
            }else{
                ans[k--]=nums[j]*nums[j];
                j--;
            }
        }
        return ans;
    }
};
// @lc code=end
