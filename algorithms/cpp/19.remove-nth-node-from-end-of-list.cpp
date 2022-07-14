/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//===========================================================================
//解題思路
//1.利用雙指標fast and slow
//2.首先fast先往前走n+1步，之後slow和fast再一起往前，直到fast的next為nullptr
//3.此時slow的next即為要刪除的點
//4.刪除後將head回傳
//===========================================================================
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummynode=new ListNode(0);
        ListNode *slow=dummynode,*fast=dummynode;
        dummynode->next=head;
        //fast dorward n+1 times first
        n++;
        while(n--){                 
            fast=fast->next;
        }
        //fast and slow  forward
        while(fast!=nullptr)        
        {
            fast=fast->next;
            slow=slow->next;
        }

        //delete nth node and return list
        ListNode *temp=slow->next;
        slow->next=slow->next->next;
        return dummynode->next;
    }
};
// @lc code=end

