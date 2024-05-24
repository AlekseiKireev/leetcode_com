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

TreeNode* Preorder(TreeNode* node1, TreeNode* node2){

    if(node1 == nullptr){
        return node2;
    }

    if(node2 == nullptr){
        return node1;
    }    

    assert(node1 != nullptr && node2 != nullptr );
    node1->val += node2->val;

    node1->left = Preorder(node1->left, node2->left);
    node1->right = Preorder(node1->right, node2->right);

    return node1;
}

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return Preorder(root1, root2);
    }
};
