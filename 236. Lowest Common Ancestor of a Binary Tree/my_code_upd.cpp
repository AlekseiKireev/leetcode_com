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

TreeNode* LCA = nullptr;

bool Found_P = false;
bool Found_Q = false;

void Travel(TreeNode* node, TreeNode* P, TreeNode* Q){

    if(node == nullptr || (Found_P && Found_Q)){return;}

    // LCA == node, которая является максимальны по высоте родителем (считая сверху) как P, так и Q
    const bool NodeIsParent_P_and_Q = (!Found_P) && (!Found_Q); // Нода W рассматривается как родитель ноды W

    if(node == P){Found_P = true;}
    if(node == Q){Found_Q = true;}

    Travel(node->left,P,Q);
    Travel(node->right,P,Q);

    // postorder проходит снизу-вверх, это гарантирует наименьшее (наибольшее по глубине) NodeIsParent_P_and_Q
    // зашли в postorder раздел и предше-е ему ноды уже помечены в preorder разделе
    if(LCA == nullptr && /*это необходимо чтобы единожды обновить LCA*/
    NodeIsParent_P_and_Q && /*услвоие, свойственное для LCA*/
    Found_P && Found_Q){LCA = node;}
}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        Travel(root, p, q);

        return LCA;
    }
};
