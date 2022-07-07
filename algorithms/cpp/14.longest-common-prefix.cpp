/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ans = strs[0];
        int j;
        for (int i = 1; i < strs.size(); i++)
        {
            for (j = 0; j < min(strs[i].length(), ans.length()); j++)
            {
                if (ans[j] != strs[i][j])
                {
                    break;
                }
            }
            ans = ans.substr(0, j);
        }
        return ans;
    }
};
// @lc code=end
