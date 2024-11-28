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

bool isValid = true;
bool IsFirst = true;
int prev;

void InOrder(TreeNode* root){

    if(root == nullptr){
        return;
    }

    InOrder(root->left);

    if(IsFirst || prev < root->val){
        prev = root->val;
        IsFirst = false;
    }else{
        isValid = false;
        return;
    }

    InOrder(root->right);

}

public:
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        return isValid;
    }
};
