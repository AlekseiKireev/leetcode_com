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

struct VectorHash {
    size_t operator()(const vector<bool>& vec) const {
        size_t hash = 0;
        for (bool b : vec) {
            hash = hash * 31 + b;
        }
        return hash;
    }
};

unordered_map<TreeNode*, int> NodeToCntChild;
unordered_map<vector<bool>, pair<TreeNode*, TreeNode*>, VectorHash> SetNodesToParent; // 2 Parent ввиду того, что надо найти две вершины


int calculateCountChildren(TreeNode* node) {
    
    if (node == nullptr) {return 0;}

    int leftCount = calculateCountChildren(node->left);
    int rightCount = calculateCountChildren(node->right);

    return NodeToCntChild[node] = leftCount + rightCount + 1;
}


vector<bool> PostOrder (TreeNode* node) {
    
    if (!node) {
        return vector<bool>(26, false);
    }


    vector<bool> left = PostOrder(node->left);
    vector<bool> right = PostOrder(node->right);

    vector<bool> current(26, false);
    current[node->val - 'a'] = true;

    for (int i = 0; i < 26; ++i) {
        current[i] = current[i] || left[i] || right[i];
    }

    if (SetNodesToParent[current].first == nullptr) {
        SetNodesToParent[current].first = node;
    } else if (SetNodesToParent[current].second == nullptr) {
        SetNodesToParent[current].second = node;
    } else {
        
        if (NodeToCntChild[SetNodesToParent[current].first] < NodeToCntChild[node]) {
            SetNodesToParent[current].second = SetNodesToParent[current].first;
            SetNodesToParent[current].first = node;
        } else if (NodeToCntChild[SetNodesToParent[current].second] < NodeToCntChild[node]) {
            SetNodesToParent[current].second = node;
        }
        
    }

    return current;
};

// calculateCountChildren{NodeToCntChild} + findEqualSubtrees {PostOrder}
pair<TreeNode*, TreeNode*> findEqualSubtrees(TreeNode* root) {
    PostOrder(root);

    auto best = pair<TreeNode*, TreeNode*>{nullptr, nullptr};
    int maxSum = 0;

    for (const auto& [vct, nodes] : SetNodesToParent) {
        const auto& [first, second] = nodes;

        if (first && second) {
            int sum = NodeToCntChild[first] + NodeToCntChild[second];
            if (sum > maxSum) {
                maxSum = sum;
                best = {first, second}; 
            }
        }
    }

    return best;
}


int main() {

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
