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

    vector<TreeNode*> getPath(TreeNode* root, int val) {
        vector<TreeNode*> path;
        while (true) {
            path.push_back(root);
            if (val < root->val) {
                root = root->left;
            }
            else if (val > root->val) {
                root = root->right;
            }
            else {
                return path;
            }
        }
    }

    TreeNode* lastCommon(const vector<TreeNode*>& v1, const vector<TreeNode*> v2) {
        assert(!v1.empty() && !v2.empty() && v1[0] == v2[0]);
        int i = 0;
        while (i < (int)v1.size() && i < (int)v2.size() && v1[i] == v2[i]) {
            i++;
        }
        return v1[i - 1];
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lastCommon(getPath(root, p->val), getPath(root, q->val));
    }
};

