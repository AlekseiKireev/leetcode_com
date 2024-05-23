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

private:

int TotalSum = 0;

void Travel(TreeNode* node, bool IsLeft){

    if(node == nullptr){
        return;
    }


    // its working!
    /*if(IsLeft && node->left == nullptr && node->right == nullptr){
        TotalSum += node->val;
    }*/

    Travel(node->left, true);

    // its working!
    /*if(IsLeft && node->left == nullptr && node->right == nullptr){
        TotalSum += node->val;
    }*/

    Travel(node->right, false);

    // its working!
    if(IsLeft && node->left == nullptr && node->right == nullptr){
        TotalSum += node->val;
    }    
}

public:
    int sumOfLeftLeaves(TreeNode* root) {
        Travel(root, false);
        return TotalSum;
    }
};
