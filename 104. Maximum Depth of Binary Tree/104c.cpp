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
 int maxDepth(TreeNode* root) { 

   if (root == nullptr) {
     return 0;
   }

   int ans = 0;
   vector<TreeNode*> curLevel; 
   curLevel. push_back(root); 
   vector<TreeNode*> nextLevel;

   while (!curLevel.empty()) {
     for (TreeNode* node : curLevel) {
       if (node->left != nullptr) { 
        nextLevel. push_back(node->left);
       }
       if (node->right != nullptr) { 
        nextLevel.push_back(node->right);
       }
     }

     nextLevel.swap(curLevel); 
     nextLevel.clear();
     ans++;
   }

   return ans;

 }
};

