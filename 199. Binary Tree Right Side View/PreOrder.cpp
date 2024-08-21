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

vector<int> BT_RightSideView;

void PreOrder(TreeNode* root, int Height = 0){

    if(root == nullptr){
        return;
    }

    if(BT_RightSideView.size() == Height){
        BT_RightSideView.push_back(root->val);
    }

    PreOrder(root->right, Height + 1);
    PreOrder(root->left, Height + 1);


}

public:
    vector<int> rightSideView(TreeNode* root) {
        
        PreOrder(root);
        return BT_RightSideView;
    }
};
