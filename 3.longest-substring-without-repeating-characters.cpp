/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //
        // int alphabet[128]={0};
        // int max_length = 0, temp;
        // for (int j = 0; j < s.size(); j++)
        // {
        //     memset(alphabet, 0, sizeof(alphabet));
        //     temp = 0;
        //     for (int i = j; i < s.size(); i++)
        //     {
        //         if (alphabet[s[i]] == 0)
        //         {
        //             temp+=1;
        //             max_length=max(max_length,temp);
        //             alphabet[s[i]] = 1;
        //         }
        //         else
        //         {
        //             max_length=max(max_length,temp);
        //             break;
        //         }
        //     }
        // }
        // return max_length;
        // ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
        // unordered_set<char> set;
        // int i = 0, j = 0, n = s.size(), ans = 0;
        // while (i < n && j < n)
        // {
        //     if (set.find(s[j]) == set.end())
        //     {
        //         set.insert(s[j++]);
        //         ans = max(ans, j - i);
        //     }
        //     else
        //     {
        //         set.erase(s[i++]);
        //     }

        // }
        // return ans;
        //
        //＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
        int alphabet[128] = {0};
        int max_length = 0;
        memset(alphabet, 0, sizeof(alphabet));
        int i = 0, j = 0, n = s.size();
        while (i < n)
        {
            alphabet[s[i]]++;
            while (alphabet[s[i]] > 1) //當alphabet[s[i]]>1時，代表出現重複，則依序將前面的陣列
            {                          //減一，直到j跑到當前i的位置為止
                alphabet[s[j++]]--;
            }
            max_length = max(max_length, i - j + 1);
            i++;
        }
        return max_length;
    }
};

// @lc code=end
