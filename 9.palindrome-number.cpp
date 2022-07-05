/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
    //     string str(to_string(x));
    //     int head=0,tail=(str.length())-1;

    //     for(;;head++,tail--){
    //       if(str[head]!=str[tail]) return false;
    //       else if(str.length() % 2==1){
    //           if(head!=tail){
    //             continue;
    //           }else{
    //            return true;
    //           }
    //       }else{
    //          if(str.length() % 2==0){
    //            if(head+1!=tail){
    //             continue;
    //            }else{
    //              return true;
    //            }
    //       }
    //     }
         
    // } 
    class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
};
// @lc code=end

