/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]==b[0]) return a[1]<b[1];
        else return a[0]>b[0];
        }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> que;
        for(int i=0;i<people.size();i++){
            int position = people[i][1];
            que.insert(que.begin() + position, people[i]);
        }
        return que;
    }
};
// @lc code=end

