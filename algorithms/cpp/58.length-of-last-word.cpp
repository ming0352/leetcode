/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
/*  解題思路
1.判斷最後一個字符是否為空格
2.假如為空格則跳至非空格處開始計算，否則直接開始累加字符數(k)
3.加入判斷是否已讀取到字串的最前端，若(i==0)且非為空格則 k++.
4.回傳結果 k
*/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.length() - 1, k = 0;
        if (s[i] == ' ')
        {
            while (s[i] == ' ')
                i--;
            while (s[i] != ' ' && i != 0)
            {
                if (i > 0)
                    i--;
                k++;
            }
            if (i == 0 && s[i] != ' ')
                k++;
        }
        else if (s[i] != ' ')
        {
            while (s[i] != ' ' && i != 0)
            {
                k++;
                if (i > 0)
                    i--;
            }
            if (i == 0 && s[i] != ' ')
                k++;
        }
        return k;
    }
};
// @lc code=end
