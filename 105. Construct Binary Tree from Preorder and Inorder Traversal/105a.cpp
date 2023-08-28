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
    const vector<int>& preorder, int preorderFirst, int preorderAfter, 
    const vector<int>& inorder, int inorderFirst, int inorderAfter
  ) {

    if (preorderFirst == preorderAfter) {return nullptr;}

    TreeNode* root = new TreeNode(preorder[preorderFirst]);

    for (int i = inorderFirst; i < inorderAfter; i++) {

      if (inorder[i] == root->val) {

        const int leftSize = i - inorderFirst;

        root->left = buildTree(
          preorder, preorderFirst + 1, preorderFirst + 1 + leftSize, 
          inorder, inorderFirst, i
        );

        root->right = buildTree(
          preorder, preorderFirst + 1 + leftSize, preorderAfter, 
          inorder, i + 1, inorderAfter
        );

        return root;
      }

    }

    throw invalid_argument("root not found in inorder");

  }

public:

  TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    return buildTree(preorder, 0, (int)preorder.size(), inorder, 0, (int)inorder.size());
  }
};

