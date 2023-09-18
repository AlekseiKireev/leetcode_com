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

    // returns height if balanced else -1
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftH = getHeight(node->left);
        if (leftH == -1) {
            return -1;
        }
        int rightH = getHeight(node->right);
        if (rightH == -1) {
            return -1;
        }
        if (abs(leftH - rightH) > 1) {
            return -1;
        }
        else {
            return max(leftH, rightH) + 1;
        }
    }
public:

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
