#include <iostream>
#include <vector>
#include <stack>
#include "Common.cc"

class Solution {
public:
  static std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> result{};
    std::stack<TreeNode*> stack;
    TreeNode* cur = root;
    while (cur != nullptr || !stack.empty()) {
      while(cur != nullptr) {
        result.push_back(cur->val);
        stack.push(cur);
        cur = cur->left;
      }
      cur = stack.top()->right;
      stack.pop();
    }
    return result;
  };
};

int main() {
  std::vector<int> res = Solution::inorderTraversal(getTree());
  for(auto val:res) {
    std::cout<<val<<std::endl;
  }
  return 0;
}