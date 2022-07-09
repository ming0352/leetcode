/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        vector<int> ans;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (i == digits.size() - 1)
                digits[i]++;
            int temp = digits[i] + carry;
            carry = temp / 10;
            digits[i] = temp % 10;

            if (i == 0 && carry != 0)
            {
                ans.push_back(carry);
                carry = 0;
            }
        }
        for (vector<int>::iterator it = digits.begin(); it != digits.end(); ++it)
        {
            ans.push_back(*it);
        }
        return ans;
    }
};
// @lc code=end
