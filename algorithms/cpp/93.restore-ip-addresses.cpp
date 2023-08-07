/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    bool isValid(string s,int start,int end){
        if (start > end) {
            return false;
        }
        if(s[start]=='0'&& start!=end) return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
    void backtracking(string s,int idx,int pointsum){
        if(idx>=s.size()) return;
        if(pointsum==3){
            if(isValid(s,idx,s.size()-1)){
                result.push_back(s);
            }
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isValid(s,idx,i)){
               s.insert(s.begin()+i+1,'.');
                pointsum++;
                backtracking(s,i+2,pointsum);
                s.erase(s.begin()+1+i);
                pointsum--; 
            }else break;
            
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s,0,0);
        return result;
    }
};
// @lc code=end

