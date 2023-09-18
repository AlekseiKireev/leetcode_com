const int ZERO = []() {

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

    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }

public:

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return
            isBalanced(root->left) && isBalanced(root->right) &&
            abs(getHeight(root->left) - getHeight(root->right)) <= 1;
    }
};
