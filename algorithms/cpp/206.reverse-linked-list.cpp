/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    //     ListNode *front = head, *tail = head;
    //     ListNode *back = head;
    //     if(head==nullptr) return head;   //如果list為空 則直接回傳head
    //     while (tail->next != nullptr) {  //找到最後一個node
    //       tail = tail->next;  // 5
    //     }
    //     if(tail==head) return head; //if node只有一個時，直接回傳

    // //  node1  -->   node 2 -->  node3 -->null
    // //  front        head        back
    // //               tail

    //     head = head->next;
    //     back = head->next;
    //     front->next = nullptr; //將第一個node指向null

    //     while (back != nullptr) {
    //       head->next = front;
    //       front = head;
    //       head = back;
    //       back = back->next;
    //     }
    //     head->next = front;
    //     return head;
    
    ListNode *front = nullptr, *ptr = head;
    if (head == nullptr) return head;
    while (head) {
      ptr = head->next;
      head->next = front;
      front = head;
      head = ptr;
    }
    return front;
  }
};
// @lc code=end
