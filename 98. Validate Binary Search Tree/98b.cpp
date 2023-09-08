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

  bool isValid(TreeNode* node, const int* min, const int* max) { 
    if (node == nullptr) {
      return true;
    }
    if (min != nullptr && !(*min < node->val)) {
      return false;
    }
    if (max != nullptr && !(node->val < *max)) {
      return false;
    } 
    return
      isValid(node->left, min, &node->val) && 
      isValid(node->right, &node->val, max);
  }

public:

  bool isValidBST(TreeNode* root) {
    return isValid(root, nullptr, nullptr);
  }
};

