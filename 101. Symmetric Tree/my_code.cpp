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
        const bool s = ChechSymmetricTree(LeftSubTree->right, RightSubTree->left);
        return s;
    }


    bool isSymmetric(TreeNode* root) {
        
        if(root == nullptr){return true;}

        return ChechSymmetricTree(root->left, root->right);
    }
};
