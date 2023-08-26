/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result;
        // method 1
        // for(int i=1;i<intervals.size();i++){
        //     if(intervals[i][0]<=intervals[i-1][1]){
        //         intervals[i][0]=min(intervals[i-1][0],intervals[i][0]);
        //         intervals[i][1]=max(intervals[i-1][1],intervals[i][1]);
        //         intervals.erase(intervals.begin()+i-1);
        //         i--;
        //     }
        // }
        
        // method 2
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=result.back()[1]){
                result.back()[1]=max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
// @lc code=end

