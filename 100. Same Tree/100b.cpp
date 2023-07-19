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
      
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push(make_pair(p, q));
      
        while (!st.empty()) {
          
            const auto pair = st.top();
            st.pop();

            const TreeNode* first = pair.first;
            const TreeNode* second = pair.second;

            if (first == nullptr && second == nullptr) {
                continue;
            }

            if (first == nullptr || second == nullptr) {
                return false;
            }

            assert(first != nullptr && second != nullptr);
            
            if (first->val != second->val) {
                return false;
            }

            st.push(make_pair(first->left, second->left));
            st.push(make_pair(first->right, second->right));
        }
        return true;
    }
};
