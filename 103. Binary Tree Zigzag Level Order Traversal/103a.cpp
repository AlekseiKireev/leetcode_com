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

  void visit(TreeNode* node, int level, vector<vector<int>> &res) { 

    if (node == nullptr) {return;} 

    if (level == (int)res.size()) {res.emplace_back();} 

    assert(level < (int)res.size()); 

    res[level].push_back(node->val); 
    visit(node->left, level + 1, res); 
    visit(node->right, level + 1, res);

  }

public:

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
    vector<vector<int>> res;
    visit(root, 0, res);
    for (int i = 1; i < (int)res.size(); i += 2) { 
      std::reverse(res[i].begin(), res[i].end()); 
    }
    return res;
  } 
  
};
