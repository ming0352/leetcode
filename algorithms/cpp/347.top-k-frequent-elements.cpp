/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
  public:
    class mycomparison {
      public:
        bool operator()(pair<int, int> &lhs, pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(*it);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> answer(k);
        for (int i = k - 1; i >= 0; i--) {
            answer[i] = pq.top().first;
            pq.pop();
        }
        return answer;
    }
};
// @lc code=end
