/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        string ans = "";
        while(i>=0||j>=0||carry){
            if(i>=0&&a[i--]=='1') carry++;
            if(j>=0&&b[j--]=='1') carry++;            
            ans.insert(0,(carry%2==1?"1":"0"));
            carry/=2;
        }  
        return ans;
    }
};
// @lc code=end
