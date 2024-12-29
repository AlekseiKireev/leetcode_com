#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <functional>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Хэш-функция для vector<bool>
struct VectorHash {
    size_t operator()(const vector<bool>& vec) const {
        size_t hash = 0;
        for (bool b : vec) {
            hash = hash * 31 + b;
        }
        return hash;
    }
};

// Словарь для подсчета количества детей в поддеревьях
unordered_map<TreeNode*, int> nodeCountMap;

unordered_map<vector<bool>, pair<TreeNode*, TreeNode*>, VectorHash> subtreeMap;

// Функция для подсчета количества детей в поддереве
int calculateCountChildren(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftCount = calculateCountChildren(node->left);
    int rightCount = calculateCountChildren(node->right);

    int totalCount = leftCount + rightCount + 1;
    nodeCountMap[node] = totalCount;

    return totalCount;
}


vector<bool> dfs (TreeNode* node) {
    
    if (!node) {
        return vector<bool>(26, false);
    }

    vector<bool> current(26, false);
    current[node->val - 'a'] = true;

    vector<bool> left = dfs(node->left);
    vector<bool> right = dfs(node->right);

    for (int i = 0; i < 26; ++i) {
        current[i] = current[i]  left[i]  right[i];
    }

    if (subtreeMap.find(current) == subtreeMap.end()) {
        subtreeMap[current] = {node, nullptr};
    } else {
        TreeNode* first = subtreeMap[current].first;
        TreeNode* second = subtreeMap[current].second;
        
        if (!second || nodeCountMap[node] > nodeCountMap[second]) {
            subtreeMap[current].second = node;
        }

        if (nodeCountMap[node] > nodeCountMap[first]) {
            swap(subtreeMap[current].first, subtreeMap[current].second);
        }
    }

    return current;
};


// Функция для поиска двух равных вершин с максимальной суммой количества вершин в их поддеревьях
pair<TreeNode*, TreeNode*> findEqualSubtrees(TreeNode* root) {
    dfs(root);

    auto best = pair<TreeNode*, TreeNode*>{nullptr, nullptr};
    int maxSum = 0;

    for (const auto& [vct, nodes] : subtreeMap) {
        const auto& [first, second] = nodes;

        if (first && second) {
            int sum = nodeCountMap[first] + nodeCountMap[second];
            if (sum > maxSum) {
                maxSum = sum;
                best = {first, second}; // Обновляем обе переменные через pair
            }
        }
    }

    return best;
}


int main() {
    // Пример использования
    TreeNode* root = new TreeNode('a',
        new TreeNode('b', new TreeNode('c'), new TreeNode('d')),
        new TreeNode('b', new TreeNode('d'), new TreeNode('c'))
    );

    calculateCountChildren(root);

    auto result = findEqualSubtrees(root);
    if (result.first && result.second) {
        cout << "First node value: " << (char)result.first->val << endl;
        cout << "Second node value: " << (char)result.second->val << endl;
    } else {
        cout << "No equal subtrees found." << endl;
    }

    return 0;
}
