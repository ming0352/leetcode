/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *topA = headA;
        ListNode *topB = headB;
        int lenA = 0, lenB = 0;

        while (topA != nullptr) {
            lenA++;
            topA = topA->next;
        }
        while (topB != nullptr) {
            lenB++;
            topB = topB->next;
        }
        topA = headA;
        topB = headB;

        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(topA, topB);
        }
        int diff = lenA - lenB;
        while (diff--) {
            topA = topA->next;
        }

        while (topA->next != nullptr) {
            if (topA == topB) {
                return topA;
            }
            topA = topA->next;
            topB = topB->next;
        }
        if (topA == topB) {
            return topA;
        }
        return nullptr;
    }
};
// @lc code=end
