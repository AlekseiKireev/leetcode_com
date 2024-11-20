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
        
        TreeNode* LCA = nullptr;
        while(LCA == nullptr){

            // обходим дерево сверху-вниз, в BST выполняется инвариант, что левый потомок < Родителя < правый потомок
            // также может произойти случай, когда LCA == root->val, для этого надо знак "="
            if(min(p->val,q->val) <= root->val && root->val <= max(p->val,q->val)){ // errror: if(min(p->val,q->val) <= root->val <= max(p->val,q->val)){
                LCA = root;
            }else{ // текущий root не является LCA, значит p и q находятся в левом или правом поддереве, надо сдвинуть указатель root в соот-е с определением BST
                root = (root->val < min(p->val,q->val) ? root->right : root->left);
                // root = (root->val < max(p->val,q->val) ? root->right : root->left); // good!
            }
        }

        return LCA;

    }
};
