class Solution {
public:

    int maxDepth(TreeNode* node) { // для каждого узла снизу-вверх подсчитывает максимальную глубину его левого и правого поддерева
        
        if(node == nullptr){return 0;}

        int LeftDepth = maxDepth(node->left);
        int RightDepth = maxDepth(node->right);

        return max(LeftDepth, RightDepth) + 1;

    }
};
