/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> qu;
    if (root) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      vector<int> tmp;
      for (int i = 0; i < size; i++) {
        Node* node = qu.front();
        qu.pop();
        tmp.emplace_back(node->val); 
        for (int i = 0; i < node->children.size(); i++) {
          if (node->children[i]) {
            qu.push(node->children[i]);
          }
        }
      }
      ans.emplace_back(tmp);
    }
    return ans;
  }
};
// @lc code=end
