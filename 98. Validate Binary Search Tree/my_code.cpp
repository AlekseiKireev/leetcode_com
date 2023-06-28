class Solution {

private:

    // функция, на основе preorder-обхода
    bool CheckDefinition(
    TreeNode* root, 
    long long LocalMax = numeric_limits<long long>::max(), 
    long long LocalMin = numeric_limits<long long>::min()
                        ){
        
        if(root == nullptr){return true;} // если root == nullptr, значит, дошли до листа, при это ветвь дерева,
                                          //  по которой дошли до леста, удовлетворяет требованиям BST, поэтому возвращаем истину

        if(root->val >= LocalMax || root->val <= LocalMin){return false;} // проверка на НЕПРАВИЛЬНЫЕ требования BST
        
        bool f = CheckDefinition(root->left, root->val, LocalMin); // начало обхода левого поддерева
        if(!f){return f;}
        bool s = CheckDefinition(root->right,LocalMax, root->val); // начало обхода правого поддерева
        return s; 
    }


public:
    bool isValidBST(TreeNode* root) {
        return CheckDefinition(root);

    }
};
