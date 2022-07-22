/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tail=nullptr;
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* temp1=dummyNode;
        int count=left-1;
        if(head->next==nullptr) return head;
        //find previous node
        while(count--){
            temp1=temp1->next;
        }
        ListNode *t; //save last node's next
        head=temp1;
        int sub=right-left;
        tail=head->next;
        //find tail
        while(sub--){
            tail=tail->next;
        }
        t=tail->next; 
        ListNode* first=head->next;
        //reverse list
        while(1){
           tail->next=head->next; 
           head->next=tail;
            head=head->next;
            if(first==tail) break;
            while(tail->next!=head){
                tail=tail->next;
                }
        }
        tail->next=t;//將剛剛記住的尾巴連起來
        return dummyNode->next;
    }
};
// @lc code=end

