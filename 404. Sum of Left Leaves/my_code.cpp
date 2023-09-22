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

    int SumLeftLeaves = 0;

    void DFS(TreeNode* root, bool IsLeftChild){ //DFS == preoder

        if(root == nullptr){return;} 

        // check on left leave
        if(IsLeftChild && 
        root->left == nullptr && 
        root->right == nullptr
        ){ // 2 и 3 аргумент -- проверка на то, что node -- лист. 1 аргумент проверряет, что лист левый.
            SumLeftLeaves += root->val;}

        DFS(root->left, true);
        DFS(root->right, false);
    }

public:

    int sumOfLeftLeaves(TreeNode* root) {
        
        DFS(root, false); // "false" ввиду "Example 2"
        return SumLeftLeaves;
    }
};

/*
class Solution {

    int DFS(TreeNode* root, bool IsLeftChild){ //DFS == preoder

        if(root == nullptr){return 0;} 

        // check on left leave
        if(IsLeftChild && 
        root->left == nullptr && 
        root->right == nullptr
        ){ // 2 и 3 аргумент -- проверка на то, что node -- лист. 1 аргумент проверряет, что лист левый.
            return root->val;}

        return DFS(root->left, true) + DFS(root->right, false);
    }

public:

    int sumOfLeftLeaves(TreeNode* root) {
               
        return DFS(root, false); // "false" ввиду "Example 2"
    }
};
*/
