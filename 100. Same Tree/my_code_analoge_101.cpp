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

        //--------------------------УСЛОВИЕ-ВЫХОДА-ИЗ-РЕКУРСИИ---------------------------------------------------------
        if(LeftNode == nullptr && RightNode == nullptr){return true;} // хотя-бы одна нода указывает НЕ на nullptr
        if(LeftNode == nullptr || RightNode == nullptr){return false;}

        if(LeftNode->val != RightNode->val){return false;}
        //--------------------------УСЛОВИЕ-ВЫХОДА-ИЗ-РЕКУРСИИ---------------------------------------------------------
        
        return (Travel(LeftNode->left, RightNode->left) && Travel(LeftNode->right, RightNode->right)); // разница с 101 в этой строке

    }

public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (Travel(p, q) && Travel(q, p)); // разница с 101 в этой строке
    }

};
