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

    int max_sum = -1001; // -1000 <= Node.val <= 1000

    int max_gain(TreeNode* root) {

        if (root == nullptr) {
            return 0; // возврат нуля так как ноды, которые ни куда не указывает имеют нулевой вес, это лоигчно
        }

        // есть возможность выбрать левое или правое поддерево, или же просто остановлюсь на своем корневом значении.
        // "0" означает, что node не рассматриваем, так как нет смысла в пути, стоимость которого меньше 0
        int l = max(max_gain(root->left), 0); 
        int r = max(max_gain(root->right), 0);
        assert(0 <= l && 0 <= r);
        
        int CurrentMaxSumPricePath = root->val + l + r; // оптимальная сумма пути в поддеревьях с текущем корнем root (путь имеет вид: l1<--l2<--...<--root-->...-->r2-->r1)
        
        
        
        max_sum = max(max_sum, CurrentMaxSumPricePath); // обновляем искомое

        assert( 0 <= max(l, r));
        return root->val + max(l, r); // "max(l, r)" необходим для того, чтобы из правого и левого поддерева с корнем root выбрать максимальный пуь и отбросить ненужную ветку
    }

    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};
