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
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        if (root->val > L) {
            sum += rangeSumBST(root->left, L, R);
        }
        if (root->val < R) {
            sum += rangeSumBST(root->right, L, R);
        }
        if (L <= root->val && root->val <= R) {
            sum += root->val;
        }
        return sum;
    }
};
