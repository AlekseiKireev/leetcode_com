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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == nullptr && q == nullptr){ // дошли до листа и не было false
            return true;
        }

        // if( p -> val != q -> val || (p == nullptr || q == nullptr)){ // error: p -> val / q -> val обращаются к памяти, но при этом p / q может быть nullptr
        if((p == nullptr || q == nullptr) || p -> val != q -> val ){ // В "(p == nullptr || q == nullptr) " оператор ||, так как не может быть p = q = nullptr, ибо такой случай обрабатвался в условном операторе выше
            return false;
            }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};
