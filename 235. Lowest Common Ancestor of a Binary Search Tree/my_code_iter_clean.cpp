/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
            }else{ // сдвигаем указатель на ноду
                root = (root->val < min(p->val,q->val) ? root->right : root->left);
            }
        }

        return LCA;

    }
};
