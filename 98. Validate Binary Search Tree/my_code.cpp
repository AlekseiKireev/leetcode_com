class Solution {

private:

    bool CheckDefinition(
    TreeNode* root, 
    long long LocalMax = numeric_limits<long long>::max(), 
    long long LocalMin = numeric_limits<long long>::min()
                        ){
        
        if(root == nullptr){return true;}


        if(root->val >= LocalMax || root->val <= LocalMin){return false;}
        
        bool f = CheckDefinition(root->left, root->val, LocalMin);
        if(!f){return f;}
        bool s = CheckDefinition(root->right,LocalMax, root->val);
        return f * s;
    }


public:
    bool isValidBST(TreeNode* root) {
        return CheckDefinition(root);

    }
};
