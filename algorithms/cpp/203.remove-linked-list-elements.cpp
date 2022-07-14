/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
//方法一
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode *temp=head,*prev=temp;
//         while(temp!=nullptr){
//             if(head==temp &&temp->val==val){
//                 ListNode* del=temp;
//                 temp=temp->next;
//                 head=temp;
//                 prev=temp;
//                 delete del;
//             }
//             else if(temp->val==val){
//                 ListNode* del=temp;
//                 prev->next=temp->next;
//                 temp=temp->next;
//                 delete del;
//             }else{
//                 if(head==temp)temp=temp->next;
//                 else{
//                     temp=temp->next;
//                     prev=prev->next;
//                 }
//             }
//         }
//         return head;
//     }
// };
//方法二
//使用DummyNode
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* DummyNode=new ListNode(-1,head);
        ListNode *temp=DummyNode,*prev=DummyNode;
        temp=temp->next;
        while(temp!=nullptr){
            if(temp->val==val){
                ListNode* del=temp;
                prev->next=temp->next;
                temp=temp->next;
                delete del;
            }else{
                    temp=temp->next;
                    prev=prev->next;
                
            }
        }
        head=DummyNode->next;
        delete DummyNode;
        return head;
    }
};
// @lc code=end

