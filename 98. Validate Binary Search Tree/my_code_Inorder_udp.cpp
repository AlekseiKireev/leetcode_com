class Solution {

private:

    bool flag = 0; // необходим для первой инициализации prev_node самым левым листком, минимальным элементов, которое содержится в данном дереве

    int prev_node;

    bool CheckDefinition(TreeNode* root){
        
        if(root == nullptr){return true;}
        
        bool f = CheckDefinition(root->left);
        if(!f){return f;}

        if(flag && prev_node >= root->val){return false;} // В правильном BST выполняется инвариант: prev_node < root->val
        else{prev_node = root->val;flag = 1;} // при первом инициализируем самым левым листком значение prev_node. Ожидается, что в таком случае prev_node = min({all val TreeNode})

        bool s = CheckDefinition(root->right);
        return s;
    }


public:
    bool isValidBST(TreeNode* root) {

        return CheckDefinition(root);

    }
};
