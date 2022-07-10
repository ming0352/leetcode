/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */


/*解題思路
1.先將初始陣列由小到大排序
2.固定一點並使用雙指標的方式來尋找其他兩點
3.當nums[i]+nums[a]+nums[b]<0時，a++，
    nums[i]+nums[a]+nums[b]>0時，b--，
    nums[i]+nums[a]+nums[b]＝0時，則push solution
4.判斷當值相同時跳下一個數，避免重複
*/


// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
        {
            return {};
        }
        if (nums[0] > 0)
        {
            return {};
        }
        for (int i = 0; i < nums.size()-2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int a = i + 1, b = nums.size() - 1;
            int s = 0;
            while (a < b)
            {
                s = nums[i] + nums[a] + nums[b];
                if (s > 0)
                {
                    b--;
                }
                else if (s < 0)
                {
                    a++;
                }
                else
                {
                    vector<int> ans_sub = {nums[i], nums[a], nums[b]};
                    ans.push_back(ans_sub);
                    while (a < b && nums[a] == ans_sub[1])
                    {
                        a++;
                    }
                    while (a < b && nums[b] == ans_sub[2])
                    {
                        b--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
