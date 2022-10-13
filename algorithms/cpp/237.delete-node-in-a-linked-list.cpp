/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
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
class Solution {
  public:
    void deleteNode(ListNode *node) {
        ListNode *nt = node->next;
        while (nt->next != nullptr) {
            node->val = nt->val;
            nt = nt->next;
            node = node->next;
        }
        node->val = nt->val;
        node->next = nullptr;
    }
};
// @lc code=end
