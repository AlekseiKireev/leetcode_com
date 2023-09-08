class Solution {

private:

    long long prev_node = numeric_limits<long long>::min(); // == самый левый узел, именно так можно было бы задать ему значение по умолчанию, 
                                                            // дабы избежать использования numeric_limits, ибо если бы у val был бы тип не int а long long, 
                                                            // то так бы делать было нельзя

    bool CheckDefinition(TreeNode* root){
        
        if(root == nullptr){return true;}
        
        bool f = CheckDefinition(root->left);
        if(!f){return f;}

        if(prev_node >= root->val){return false;}
        else{prev_node = root->val;}

        bool s = CheckDefinition(root->right);
        return s;
    }


public:
    bool isValidBST(TreeNode* root) {
        return CheckDefinition(root);

    }
};
