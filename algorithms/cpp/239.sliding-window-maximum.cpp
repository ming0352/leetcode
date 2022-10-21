/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
    class myqueue {
      public:
        deque<int> dq;
        void pop(int val) {
            if (!dq.empty() && val == dq.front()) {
                dq.pop_front();
            }
        }
        void push(int val) {
            while (!dq.empty() && dq.back() < val) {
                dq.pop_back();
            }
            dq.push_back(val);
        }
        int front() { return dq.front(); }
    };

  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;
        myqueue qu;
        int max = INT_MIN;
        for (int i = 0; i < k; i++) {
            qu.push(nums[i]);
        }
        ans.push_back(qu.front());
        for (int i = k; i < nums.size(); i++) {
            qu.pop(nums[i - k]);
            qu.push(nums[i]);
            ans.push_back(qu.front());
        }

        return ans;
    }
};
// @lc code=end
