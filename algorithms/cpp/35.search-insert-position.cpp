/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = (high + low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

// why to return low ?
// Because when high = low+1, then mid = low.
// If the target > nums[mid], then low = mid + 1 = high. The target position can be low or high, since they are the same.
// but if the target < nums[mid], then high = mid - 1 = low - 1. The target position must be low, not the high.
// @lc code=end
