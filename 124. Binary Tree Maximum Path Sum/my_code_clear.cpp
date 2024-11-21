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
/*
Time complexity : O(n)
Space complexity : O(h)
*/ 
class Solution {

int Sum = -1001;

int PostOrder(TreeNode* root){

    if(root == nullptr){
        return 0;
    }
    int L = max(PostOrder(root->left), 0);
    int R = max(PostOrder(root->right), 0);

    int RootSum = root->val + L + R;
    Sum = max(Sum, RootSum);
    return root->val + max(L, R);
}


public:
    int maxPathSum(TreeNode* root) {
        
        PostOrder(root);
        return Sum;
    }
};
