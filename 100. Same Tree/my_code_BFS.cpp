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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<pair<TreeNode*, TreeNode*>> BurningVertexes;
        BurningVertexes.push({p, q});

        while(BurningVertexes.empty() == false){

            const TreeNode* pNode = BurningVertexes.front().first;
            const TreeNode* qNode = BurningVertexes.front().second;
            BurningVertexes.pop();

            if(pNode == nullptr && qNode == nullptr){continue; }
            if(pNode == nullptr || qNode == nullptr){return false; }

            if(pNode->val != qNode->val){return false; }

            BurningVertexes.push({pNode->left, qNode->left});
            BurningVertexes.push({pNode->right, qNode->right});
            
        }

        return true;
    }
};
