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
      TreeNode* buildTree(
      const vector<int>& preorder,int preorderFirst, int preorderAfter, 
      const vector<int>& inorder,int inorderFirst, int inorderAfter, 
      const unordered_map<int, int>& valueToIndex
   ) {

      if (preorderFirst == preorderAfter) {return nullptr;}

      TreeNode* root = new TreeNode(preorder[preorderFirst]);
      int i = valueToIndex.find(root->val)->second; // <--> int i = valueToIndex.at(preorder[preorderFirst]);
      int leftSize = i - inorderFirst;

      root->left = buildTree(
         preorder, preorderFirst + 1, preorderFirst + 1 + leftSize,
         inorder, inorderFirst, i, 
         valueToIndex
      );

      root->right = buildTree(
         preorder, preorderFirst + 1 + leftSize, preorderAfter, 
         inorder, i + 1, inorderAfter, 
         valueToIndex
      );

      return root;
   }

public:

   TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
         
      unordered_map<int, int> valueToIndex;
      for (int i = 0; i < (int)inorder.size(); i++) {valueToIndex[inorder[i]] = i;}
         
      return buildTree(preorder, 0, (int)preorder.size(), inorder, 0, (int)inorder.size(), valueToIndex);
   }
};
