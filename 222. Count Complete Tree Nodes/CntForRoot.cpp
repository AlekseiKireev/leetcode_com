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

int CntNodes = 0;

void AnyOrder(TreeNode* root){

    if (root == nullptr){
      return;
    }
    ++CntNodes;

    AnyOrder(root->left);
    AnyOrder(root->right);


}

public:
    int countNodes(TreeNode* root) {
        AnyOrder(root);
        return CntNodes;
    }
};
