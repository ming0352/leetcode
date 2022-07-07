/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        // 暴力法
        //     unsigned int i=1;
        //     if(x==0)return 0;
        //     while((i*i)<=x){
        //        i++;
        //     }
        // return --i;
        if (x == 0 or x == 1)
        {
            return x;
        }
        unsigned long int mid, low = 1, high = x / 2, val;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid > x)
            {
                high = mid - 1;
            }
            if (mid * mid < x)
            {
                low = mid + 1;
                val = mid;
            }
        }
        return val;
    }
};
// @lc code=end
