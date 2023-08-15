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

vector<vector<int>> ZigzagLevel; // map : height --> nodes at this height

void Visited(TreeNode* node, int Height){

    if(node == nullptr){return;}

    if(Height == ZigzagLevel.size()){ZigzagLevel.push_back(vector<int>());}

    ZigzagLevel[Height].push_back(node->val);
    
    Visited(node->left, Height + 1);
    Visited(node->right, Height + 1);
}

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        Visited(root, 0);
        return ZigzagLevel;
    }
};
