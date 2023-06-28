class Solution { // см. комментарии в my_code.cpp

private:

    bool CheckDefinition(
    TreeNode* root, 
    TreeNode* LocalMax = nullptr, 
    TreeNode* LocalMin = nullptr
                        ){
        
        if(root == nullptr){return true;}


        if(LocalMax && root->val >= LocalMax->val){return false;}
        if(LocalMin && root->val <= LocalMin->val){return false;}
        
        bool f = CheckDefinition(root->left, root, LocalMin);
        if(!f){return f;}
        bool s = CheckDefinition(root->right,LocalMax, root);
        return s;
    }


public:
    bool isValidBST(TreeNode* root) {
        return CheckDefinition(root);

    }
};
