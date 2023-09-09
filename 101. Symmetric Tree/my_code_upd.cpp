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

private:

    // На основе my_code.cpp можно сделать вывод, что подходит любой вид рекурсивного обхода
    bool Travel(TreeNode* LeftNode, TreeNode* RightNode){

        if(LeftNode == nullptr && RightNode == nullptr){return true;}
        if(LeftNode == nullptr || RightNode == nullptr){return false;}

        if(LeftNode->val != RightNode->val){return false;}

        return (Travel(LeftNode->left, RightNode->right) && Travel(LeftNode->right, RightNode->left));

    }

public:

    bool isSymmetric(TreeNode* root) {
        return (root == nullptr ? false : Travel(root->left, root->right));
    }

};
