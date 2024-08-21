https://leetcode.com/problems/binary-tree-right-side-view/description/

https://walkccc.me/LeetCode/problems/199/

У Федора Меньшикова разбор отсут-т!

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
    public:
        vector<int> rightSideView(TreeNode* root) {
    
            vector<int> A;
    
            for(;root != nullptr;root = root->right){
                A.push_back(root->val);
            }
    
            return  A;
        }
    };
    /*
    Input
    root =
    [1,2]
    
    Output
    [1]
    Expected
    [1,2]
    */
