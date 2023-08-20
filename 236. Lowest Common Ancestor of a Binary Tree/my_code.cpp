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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* y) {
            
    // базовый случай: пустое дерево
    if (root == nullptr) {return nullptr;}
 
    // если и `x`, и `y` меньше корня, LCA существует в левом поддереве
    if (root->val > max(x->val, y->val)) {
        return lowestCommonAncestor(root->left, x, y);
    }
 
    // если и `x`, и `y` больше корня, LCA существует в правом поддереве
    else if (root->val < min(x->val, y->val)) {
        return lowestCommonAncestor(root->right, x, y);
    }
 
    // если один ключ больше (или равен) корневого и один ключ меньше
    // (или равно), чем корень, то текущий узел — LCA
    return root;
    }
};
