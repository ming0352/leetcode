/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
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
    Node* ans = root;
    queue<Node*> qu;
    Node* first = nullptr;
    Node* cur = nullptr;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      first = nullptr;
      cur = nullptr;
      for (int i = 0; i < size; i++) {
        Node* node = qu.front();
        if (!first) {
          first = node;
          cur = first;
        } else {
          cur->next = node;
          cur = cur->next;
        }
        qu.pop();
        node->next = nullptr;
        if (node->left) {
          qu.push(node->left);
        }
        if (node->right) {
          qu.push(node->right);
        }
        if (i == size - 1) {
          cur->next = nullptr;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
