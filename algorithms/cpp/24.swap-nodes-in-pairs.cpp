/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummynode=new ListNode(0);
        ListNode *temp=dummynode;
        dummynode->next=head;
        while(temp->next!=nullptr &&temp->next->next!=nullptr){
            ListNode* tmp1=temp->next;//1
            ListNode *tmp2=temp->next->next->next;//3

            temp->next=temp->next->next;//d->2
            temp->next->next=tmp1;
            temp->next->next->next=tmp2;

            temp=temp->next->next;
        }
        return dummynode->next;
    }
};
// @lc code=end

