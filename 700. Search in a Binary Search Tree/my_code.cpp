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
    TreeNode* searchBST(TreeNode* root, const int val) {
        
        TreeNode* CurNode = root;

        while(CurNode != nullptr){

            if(CurNode->val == val){return CurNode;}
            CurNode = ((CurNode->val < val) ? CurNode->right : CurNode->left);
            

        }

        return nullptr;
    }
};
