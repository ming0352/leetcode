/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */
//解題思路
//1.把string當成stack來用，若不為#則push，否則pop出去
//2.最後比較兩個字串是否相同
// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        string S = "", T = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '#')
            {
                S += s[i];
            }
            else
            {
                if (!S.empty())
                {
                    S.pop_back();
                }
            }
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != '#')
            {
                T += t[i];
            }
            else
            {
                if (!T.empty())
                {
                    T.pop_back();
                }
            }
        }

        return S == T;
    }
};
// @lc code=end
