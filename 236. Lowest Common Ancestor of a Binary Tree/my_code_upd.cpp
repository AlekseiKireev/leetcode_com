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

TreeNode* LCA = nullptr;

bool Found_P = false;
bool Found_Q = false;

TreeNode* Q;
TreeNode* P;

private:

void travel(TreeNode* node){

    if(node == nullptr){return;}
    if(Found_P && Found_Q){return;}

    // Проверка на то, может ли текуищй узел быть потенциальным родителем p и q. 
    // По условию необходимо найти нижайшего родителя p и q. 
    // node может быть родителем / LCA, если расположена не ниже [выше либо равен] p или q.
    bool CheckNodeOnParentP_or_Q = (! Found_P) && (! Found_Q); // == CNOP

    if(node == Q){ Found_Q = true; }
    if(node == P){ Found_P = true; }

    travel(node->left);
    travel(node->right);

    if(LCA == nullptr && CheckNodeOnParentP_or_Q && Found_P && Found_Q){LCA = node;}

}

public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        Q = q;
        P = p;

        travel(root);
        return LCA;

    }

};
