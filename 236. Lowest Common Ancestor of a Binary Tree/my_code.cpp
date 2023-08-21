/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:

bool pFound = false;
bool qFound = false;

const TreeNode* P;
const TreeNode* Q;

TreeNode* LCA;

private:

void Traversal(TreeNode* node){

    if(node == nullptr){return;}
    if(pFound && qFound){return;}


    Traversal(node->left);
    Traversal(node->right);

    /*

    if(node == P){pFound = true;}
    if(node == Q){qFound = true;}

    if(pFound && qFound && ){LCA = node;}
    */
}

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        P = p;
        Q = q;

        Traversal(root);

        return LCA;
    }

};
