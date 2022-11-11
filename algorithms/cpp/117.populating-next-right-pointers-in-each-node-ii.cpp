/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
 public:
  Node* connect(Node* root) {
    queue<Node*> qu;
    if (root) {
      qu.push(root);
    }
    Node *cur = nullptr;
    while (!qu.empty()) {
      cur = nullptr;
      int size = qu.size();
      for (int i = 0; i < size; i++) {
        Node* node = qu.front();
        if (cur == nullptr) {
          cur = node;
        } else {
          cur->next = node;
          cur = cur->next;
        }
        qu.pop();
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
      }
      cur->next = nullptr;
    }
    return root;
  }
};
// @lc code=end
