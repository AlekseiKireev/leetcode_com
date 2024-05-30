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

bool Ans = true;

private:

    // На основе my_code.cpp можно сделать вывод, что подходит любой вид рекурсивного обхода
    void Travel(TreeNode* LeftNode, TreeNode* RightNode){

        
        //--------------------------УСЛОВИЕ-ВЫХОДА-ИЗ-РЕКУРСИИ---------------------------------------------------------
        if(LeftNode == nullptr && RightNode == nullptr){return;} // хотя-бы одна нода указывает НЕ на nullptr
        if(LeftNode == nullptr || RightNode == nullptr){
            Ans = false;
            return;
        }

        if(LeftNode->val != RightNode->val){
            Ans = false;
            return;
        }
        //--------------------------УСЛОВИЕ-ВЫХОДА-ИЗ-РЕКУРСИИ---------------------------------------------------------
        Travel(LeftNode->left, RightNode->left) ;
        Travel(LeftNode->right, RightNode->right);

    }

public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        Travel(p, q);
        return Ans;
    }

};
