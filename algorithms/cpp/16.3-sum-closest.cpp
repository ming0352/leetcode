/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
        {
            return 0;
        }
        else if (nums.size() == 3)
        {
            return nums[0] + nums[1] + nums[2];
        }
        int temp_min = 99999, sub;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int low = i + 1, high = nums.size() - 1;
            int sum = 0;

            while (low < high)
            {
                sum= nums[i] + nums[low] + nums[high];
                sub = max(target, sum) - min(target, sum);
                if(sum==target)
                {
                    return target;
                }
                if (sum > target)
                {
                    if (temp_min > sub)
                    {
                        temp_min = sub;
                        ans = sum;
                    }
                    high--;
                }
                else if (sum < target)
                {
                    if (temp_min > sub)
                    {
                        temp_min = sub;
                        ans = sum;
                    }
                    low++;
                }
                
            }
        }
        return ans;
    }
};
// @lc code=end
