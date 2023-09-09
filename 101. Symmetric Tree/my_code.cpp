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

    bool ChechSymmetricTree(TreeNode* LeftSubTree, TreeNode* RightSubTree){

        if(LeftSubTree == nullptr && RightSubTree == nullptr){return true;}

        if(LeftSubTree == nullptr || RightSubTree == nullptr){return false;}

        assert(LeftSubTree != nullptr && RightSubTree != nullptr);
        if(LeftSubTree->val != RightSubTree->val){return false;}

        //equiv return ChechSymmetricTree(LeftSubTree->left, RightSubTree->right) && ChechSymmetricTree(LeftSubTree->right, RightSubTree->left);
        const bool f = ChechSymmetricTree(LeftSubTree->left, RightSubTree->right);
        if(!f){return f;}
        
        /* // inorder bypass is good!
        assert(LeftSubTree != nullptr && RightSubTree != nullptr);
        if(LeftSubTree->val != RightSubTree->val){return false;}
        */
        
        const bool s = ChechSymmetricTree(LeftSubTree->right, RightSubTree->left);

        /* // postorder bypass is good!
        assert(LeftSubTree != nullptr && RightSubTree != nullptr);
        if(LeftSubTree->val != RightSubTree->val){return false;}
        */
        
        return s;
    }


    bool isSymmetric(TreeNode* root) {
        
        if(root == nullptr){return true;}

        return ChechSymmetricTree(root->left, root->right);
    }
};
