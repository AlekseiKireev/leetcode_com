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

unordered_map<TreeNode*, int> nodeCountMap;

int calculateCountChildren(TreeNode* node/*, unordered_map<TreeNode*, int>& nodeCountMap*/) {
    if (node == nullptr) {
        return 0;
    }

    // Рекурсивно вычисляем количество вершин в левом и правом поддеревьях
    int leftCount = calculateCountChildren(node->left/*, nodeCountMap*/);
    int rightCount = calculateCountChildren(node->right/*, nodeCountMap*/);

    // Текущее количество вершин
    int totalCount = leftCount + rightCount + 1;

    // Сохраняем результат для текущего узла
    nodeCountMap[node] = totalCount;

    return totalCount;
}

public:
    int countNodes(TreeNode* root) {
        calculateCountChildren(root);
        return nodeCountMap[root];
    }
};

/*
class Solution {

unordered_map<TreeNode*, int> nodeCountMap;

int calculateCountChildren(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    // Рекурсивно вычисляем количество вершин в левом и правом поддеревьях
    int leftCount = calculateCountChildren(node->left);
    int rightCount = calculateCountChildren(node->right);

    return nodeCountMap[node] = leftCount + rightCount + 1;
}

public:
    int countNodes(TreeNode* root) {
        calculateCountChildren(root);
        return nodeCountMap[root];
    }
};
*/
