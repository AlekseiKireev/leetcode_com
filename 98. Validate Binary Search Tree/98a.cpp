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

  bool isValid(TreeNode* node, int min, int max) {
    if (node == nullptr) {
      return true;
    }
    if (!(min <= node->val && node->val <= max)) {
      return false;
    }
    if (node->val == INT_MIN && node->left != nullptr) {
      return false;
    }
    if (node->val != INT_MIN && !isValid(node->left, min, node->val - 1)) { 
      return false;
    }
    if (node->val == INT_MAX && node->right != nullptr) {
      return false;
    }
    if (node->val != INT_MAX && !isValid(node->right, node->val + 1, max)) { 
      return false;
    }
    return true;
  }

public:

  bool isValidBST(TreeNode* root) {
    return isValid(root, INT_MIN, INT_MAX);
  }
};
