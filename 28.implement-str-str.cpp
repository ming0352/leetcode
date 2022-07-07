/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        //////////  prefix table
        vector<int> table(needle.length(), 0);
        for (int i = 0, j = 1; j < needle.length();)
        {
            if (needle[i] != needle[j])
            {
                if (i != 0)
                {
                    i = table[i - 1];
                }
                else
                {
                    table[j++] = i;
                }
            }
            else
            {
                table[j++] = ++i;
            }
        }
        ////////////////////////////////////kmp
        int n = haystack.length();
        int m = needle.length();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    i = i - table[j - 1];
                    j = 0;
                }
                else
                    i++;
            }
        }
        return j == m ? i - m : -1;
    }
};
// @lc code=end

