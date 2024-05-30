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

int CurMinNode;
bool NotExistCurMinNode = true;
bool TreeIsBST = true;

void InOrder(TreeNode* node){

    if(node == nullptr){
        return;
    }

    InOrder(node->left);
    
    if(NotExistCurMinNode || CurMinNode < node->val){
        
        CurMinNode = node->val;
        NotExistCurMinNode = false;
    }else{
        TreeIsBST = false;
        return;
    }

    InOrder(node->right);
}

public:
    bool isValidBST(TreeNode* root) {
        InOrder(root);
        return TreeIsBST;
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
