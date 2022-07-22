/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
/*
解題思路
1.建立兩個dummynode，分別用來指向大於等於x的list(bdum)和小於x的list(fdum)
2.當curr不為空則依序將大於等於的list及小於的list建立起來
3.最後把兩個list連起來，重新指定head為fdum->next，並回傳
*/
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *fdum = new ListNode(-1), *front = fdum;
    ListNode *bdum = new ListNode(-1), *back = bdum;
    ListNode* curr = head;
    //分別建立list
    while (curr) {
      if (curr->val < x) {
        front->next = curr;
        front = curr;
      } else {
        back->next = curr;
        back = curr;
      }
      curr = curr->next;
    }
    //將兩個list連接
    front->next = bdum->next;
    back->next = nullptr;
    head = fdum->next;
    delete fdum, bdum;
    return head;
  }
};
// @lc code=end
