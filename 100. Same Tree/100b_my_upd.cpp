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
          
            const auto [pNode, qNode] = st.top();
            st.pop();

            if (pNode == nullptr && qNode == nullptr) {continue;} // дошли до листа

            if (pNode == nullptr || qNode == nullptr) {return false;}

            assert(pNode != nullptr && qNode != nullptr);
            
            if (pNode->val != qNode->val) {return false;}


            st.push(make_pair(pNode->left, qNode->left));
            st.push(make_pair(pNode->right, qNode->right));
        }
        return true;
    }
};
