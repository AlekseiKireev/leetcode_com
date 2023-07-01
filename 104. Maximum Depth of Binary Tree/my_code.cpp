class Solution {
public:

    int maxDepth(TreeNode* root) {
        
        if(root == nullptr){return 0;}

        int LeftDepth = maxDepth(root->left);
        int RightDepth = maxDepth(root->right);

        return max(LeftDepth, RightDepth) + 1;

    }
};
