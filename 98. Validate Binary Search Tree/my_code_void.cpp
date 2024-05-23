class Solution {

bool Result = true;

long long RangesMin;// = numeric_limits<long long>::min();

bool flag = false;

void InOrder(TreeNode* node){

    if(node == nullptr){return;}

    InOrder(node->left);

    if(flag == false || RangesMin < node->val){ // RangesMin <= node->val --> Input root = [2,2,2]  Output true Expected false
        RangesMin = node->val;
        flag = true;
    }else{
        Result = false;
        return;
    }

    InOrder(node->right);
}

public:
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        return Result;
    }
};

/*
class Solution {

bool Result = true;

long long RangesMin = numeric_limits<long long>::min();

void InOrder(TreeNode* node){

    if(node == nullptr){return;}

    InOrder(node->left);

    if(RangesMin < node->val){ // RangesMin <= node->val --> Input root = [2,2,2]  Output true Expected false
        RangesMin = node->val;
    }else{
        Result = false;
        return;
    }

    InOrder(node->right);
}

public:
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        return Result;
    }
};
*/
