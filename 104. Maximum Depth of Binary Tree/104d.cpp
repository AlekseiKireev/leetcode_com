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

 struct Pair {
   TreeNode* node; 

   int level;
 };

public:
 int maxDepth(TreeNode* root) {
   if (root == nullptr) {
     return 0;
   }
   int ans = 0;
   stack<Pair, vector<Pair>> toProcess; 
   toProcess.push(Pair{root, 1});
   while (!toProcess.empty()) {
     Pair p = toProcess.top();
     toProcess. pop();
     ans = max(ans, p.level);
     if (p.node->left != nullptr) {
       toProcess.push(Pair{p.node->left, p.level + 1});
     }
     if (p.node->right != nullptr) {
       toProcess.push(Pair{p.node->right, p.level + 1});
     }
   }
 
  return ans;
 } 
};
