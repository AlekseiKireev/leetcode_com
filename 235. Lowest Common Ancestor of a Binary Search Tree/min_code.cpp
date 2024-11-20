/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Time complexity : O(h)
Space complexity : O(1)
*/   
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {        

        while((root->val - p->val)*(root->val - q->val) > 0){

            root = (min(p->val, q->val) < root->val) ? root->left : root->right;
        }

        return root;
    }
};
