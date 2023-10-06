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

    TreeNode* Add(TreeNode* BST, int Value){

        if(BST == nullptr){return (new TreeNode(Value));}

        if(Value < BST->val){BST->left = Add(BST->left, Value);}
        if(BST->val < Value){BST->right = Add(BST->right, Value);}

        return BST;
    }

public:

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* BST = nullptr;

        for(const int Value : preorder){
            BST = Add(BST, Value);
        }

        return BST;
    }

};
