/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
  public:
    int fib(int n) {
        // f(n)=f(n-1)+f(n-2)
        int sum = 0;
        int dp[2];
        if(n<=1) return n;
        dp[0]=0;
        dp[1]=1;
        for(int i = 2; i <= n; i++) {
            sum=dp[0]+dp[1];
            dp[0]=dp[1];
            dp[1]=sum;
        }
        return dp[1];
    }
};
// @lc code=end
