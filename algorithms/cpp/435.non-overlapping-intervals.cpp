/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int c=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>intervals[i][0]){
                c++;
                intervals[i][1]=min(intervals[i-1][1],intervals[i][1]);
            }
        }
        return c;
    }
};
// @lc code=end

