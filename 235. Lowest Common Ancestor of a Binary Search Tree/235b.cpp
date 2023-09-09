/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
    int pVal = p->val;
    int qVal = q->val; 
    while (true) {
      int val = root->val;
      if (pVal < val && qVal < val) {
        root = root->left;
      } else if (pVal > val && qVal > val) {
        root = root->right;
      } else {
        return root;
        }	
     }	
  }
};
