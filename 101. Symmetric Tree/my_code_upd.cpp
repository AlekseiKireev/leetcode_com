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
/*
Time complexity : O(n)
Space complexity : O(h)
*/    
class Solution {

private:

    // На основе my_code.cpp можно сделать вывод, что подходит любой вид рекурсивного обхода
    bool Travel(TreeNode* LeftNode, TreeNode* RightNode){

        //--------------------------УСЛОВИЕ-ВЫХОДА-ИЗ-РЕКУРСИИ---------------------------------------------------------
        if(LeftNode == nullptr && RightNode == nullptr){return true;} // хотя-бы одна нода указывает НЕ на nullptr
        if(LeftNode == nullptr || RightNode == nullptr){return false;}

        if(LeftNode->val != RightNode->val){return false;}
        //--------------------------УСЛОВИЕ-ВЫХОДА-ИЗ-РЕКУРСИИ---------------------------------------------------------
        
        return (Travel(LeftNode->left, RightNode->right) && Travel(LeftNode->right, RightNode->left));

    }

public:

    bool isSymmetric(TreeNode* root) {
        return (Travel(root->left, root->right));
    }

};
