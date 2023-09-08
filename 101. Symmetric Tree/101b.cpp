/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution { 
public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    stack<pair<TreeNode*, TreeNode*>, vector<pair<TreeNode*, TreeNode*>>> st; 
    st.push({root->left, root->right});
    while (!st.empty()) {
      TreeNode* left;
      TreeNode* right;
      tie(left, right) = st.top();
      st.pop();
      if (left == nullptr && right == nullptr) {
        continue;
      }
      if (left == nullptr || right == nullptr) {
        return false;
      }
      if (left->val != right->val) {
        return false;
      }
      st.push({left->left, right->right});
      st.push({left->right, right->left});
    }
    return true;
  }
};

