/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    TreeNode* Travel(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        // swap(node->left, node->right); // good! PreOrder: меняется сверху вниз
        Travel(node->left);

        // InOrder:
        // обработали левое поддерево
        // Потом поменяли местами детей
        // Затем идёте в node->right, но это уже бывшее левое поддерево
        // В итоге: одно поддерево обрабатывается дважды другое — ни разу
        // swap(node->left, node->right); // error!

        Travel(node->right);
        swap(node->left, node->right); // good! PostOrder: меняется снизу вверх
        return node;
    }

public:
    TreeNode* invertTree(TreeNode* root) { return Travel(root); }
};
