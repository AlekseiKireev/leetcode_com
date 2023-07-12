const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {return 0;}

        int sum;
        if (
        root->left != nullptr && 
        root->left->left == nullptr && 
        root->left->right == nullptr
        ) {sum = root->left->val;} 
        else {sum = sumOfLeftLeaves(root->left);}

        return sum + sumOfLeftLeaves(root->right);
    }
};
