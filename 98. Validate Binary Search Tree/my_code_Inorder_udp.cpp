class Solution {

private:

    bool flag = 0;

    int prev_node;

    bool CheckDefinition(
    TreeNode* root){
        
        if(root == nullptr){return true;}
        
        bool f = CheckDefinition(root->left);
        if(!f){return f;}

        if(flag && prev_node >= root->val){return false;}
        else{prev_node = root->val;flag = 1;}

        bool s = CheckDefinition(root->right);
        return s;
    }


public:
    bool isValidBST(TreeNode* root) {

        return CheckDefinition(root);

    }
};
