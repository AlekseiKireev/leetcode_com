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

  void visit(TreeNode* node, int level, vector<vector<int>> &ans) { 

    if (node == nullptr) {return;}

    if (level == (int)ans.size()) {ans.push_back(vector<int>());}

    ans[level].push_back(node->val); 

    visit(node->left, level + 1, ans); 
    visit(node->right, level + 1, ans);

  }

public:

  vector<vector<int>> levelOrder(TreeNode* root) { 
    vector<vector<int>> ans;
    visit(root, 0, ans);
    return ans;
  }

};
