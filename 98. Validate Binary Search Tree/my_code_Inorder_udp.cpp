/*
Time complexity : O(n)
Space complexity : O(h)
*/ 
// решение через свойства InOrder обхода: в BST последовательность возрастает
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
/*
class Solution {

bool flag = true;
int prev_node = 0;

    bool isBST(TreeNode* root, bool& flag, int& prev_node){
        if(root == nullptr){return true;}

        bool isValidBST = isBST(root->left, flag, prev_node);
        if(isValidBST == false){return false;}

        if(flag || prev_node < root->val){
            prev_node = root->val;
            flag = false; // опускаем флаг, так как впервые обновили значение prev_node
        }else{
            return false;
            
        }
        
        return isBST(root->right, flag, prev_node);
    }

public:
    bool isValidBST(TreeNode* root) {
       return isBST(root, flag, prev_node);
    }
};
*/
