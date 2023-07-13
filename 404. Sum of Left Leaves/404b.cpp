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

    int sumOfLeftLeaves(TreeNode* node, bool isLeft) {

        if (node == nullptr) { return 0; }

        if (node->left == nullptr && node->right == nullptr) {
            if (isLeft) {
                return node->val;
            }
            else {
                return 0;
            }
        }

        return
            sumOfLeftLeaves(node->left, true) + sumOfLeftLeaves(node->right, false);
    }

public:

    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
};

/* // https://leetcode.com/problems/sum-of-left-leaves/solutions/88951/3-line-recursive-c-solution-no-need-to-explain/
int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
    if (!root) return 0;
    if (!root->left && !root->right) return isleft ? root->val : 0;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}
*/

/* // https://leetcode.com/problems/sum-of-left-leaves/solutions/1558748/c-simple-dfs-100-faster-test-run/

class Solution {
public:
    
    int total = 0;
    
    void DFS(bool left, TreeNode* current){
        
        if (current == NULL){return;}
        
        if (left && current->left == NULL && current->right == NULL){
            total += current->val;
            return;
        }
        
        DFS(true, current->left);
        DFS(false, current->right);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        DFS(false, root);
        return total;
    }
};
*/
