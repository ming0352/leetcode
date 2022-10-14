/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
// method1
/*
class Solution {
  public:
    ListNode *deleteMiddle(ListNode *head) {
        int n = 0;
        ListNode *curr = head, *nt = head->next;
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }
        if (n == 1)
            return nullptr;
        curr = head;
        int del = ((n - n % 2) / 2) - 1;
        while (del--) {
            curr = curr->next;
        }
        nt = curr->next;
        curr->next = nt->next;
        delete nt;
        return head;
    }
};
*/
// method2
class Solution {
  public:
    ListNode *deleteMiddle(ListNode *head) {
        if (head->next == nullptr)
            return nullptr;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = slow->next->next;
        delete fast;
        return head;
    }
};
// @lc code=end
