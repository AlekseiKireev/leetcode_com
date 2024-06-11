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

int Ans = 0;

int PostOrder(TreeNode* node){

    if(node == nullptr){
        return 0;
    }

    int L = PostOrder(node->left) ;
    
    int R = PostOrder(node->right) ;
    
     // "The length of a path between two nodes is represented by the number of edges between them." -->
     // не надо никакго +1 / -1
    Ans = max(Ans, L + R);

    return max(L, R) + 1;
}

public:
    int diameterOfBinaryTree(TreeNode* root) {
        PostOrder(root);
        return Ans;
    }
};
