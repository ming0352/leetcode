/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0,next=0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                swap(nums[i], nums[next++]);
            }
        }
    }
}

;
// @lc code=end
