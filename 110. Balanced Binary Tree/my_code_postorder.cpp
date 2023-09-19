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

private:

int Travel(TreeNode* node){

    if(node == nullptr){return 0;}
    
    int LeftRight = Travel(node->left);
    if(LeftRight == -1){return -1;}
    int RightRight = Travel(node->right);
    if(RightRight == -1){return -1;}

    if(abs(RightRight - LeftRight) > 1){return -1;} // not Height-Balanced

    return max(LeftRight, RightRight) + 1;
}

public:
    bool isBalanced(TreeNode* root) {
        
        return Travel(root) != -1;

    }
};
