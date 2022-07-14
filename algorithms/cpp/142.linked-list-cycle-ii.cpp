/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//解題思路
// 1.利用快慢指針，快的走兩步，慢的走一步，當慢指針的等於快指針時，即代表有cycle
// 2.此時fast即為相遇點，將slow重設為head，並且兩個指標個走一步，最終相遇點即為cycle起點
// 3.參考解說：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0142.环形链表II.md
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    // ListNode *slow = head, *fast = head, *meet = nullptr;
    // while (fast != nullptr && fast->next != nullptr) {
    //   fast = fast->next->next;
    //   slow = slow->next;
    //   if (slow == fast) {
    //     meet = fast;
    //     break;
    //   }
    // }
    // ListNode *n1, *n2 = head;
    // if (meet != nullptr) {
    //   n1 = meet;
    //   while (n1 != n2) {
    //     n1 = n1->next;
    //     n2 = n2->next;
    //   }
    //   return n2;
    // }
    // return NULL;

    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return fast;
      }
    }
    return NULL;
  }
};
// @lc code=end
