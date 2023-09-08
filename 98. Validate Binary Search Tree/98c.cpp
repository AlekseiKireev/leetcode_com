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

     bool isValid(TreeNode* node, int min, bool isMin, int max, bool isMax) { 
          if (node == nullptr) {
                return true;
          }
          if (isMin && !(min < node->val)) {
                return false;
          }
          if (isMax && !(node->val < max)) {
                return false;
          } 
          return
          isValid(node->left, min, isMin, node->val, true) && 
          isValid(node->right, node->val, true, max, isMax);
     }
public:
     bool isValidBST(TreeNode* root) {
        return isValid(root, 0, false, 0, false);
      }
};
