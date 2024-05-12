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

/*
class Solution {

  void visit(TreeNode* node, int level, vector<vector<int>> &res) { 

    if (node == nullptr) {return;} 

    if (level == (int)res.size()) {
        res.push_back({node->val});
    }else{
        res[level].push_back(node->val); 
    }

    assert(level < (int)res.size()); 

    
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
*/

/*
class Solution {

void travel(TreeNode* root, vector<vector<int>>& Ans, int& MaxDepth, int Level = 0){

    if(root == nullptr){return;}

    Ans[Level].push_back(root->val);
    ++Level;
    MaxDepth = max(MaxDepth, Level);

    travel(root->left, Ans, MaxDepth, Level);
    travel(root->right, Ans, MaxDepth, Level);
}

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> Ans(2000);
        
        int MaxDepth = 0;
        travel(root, Ans, MaxDepth);
        Ans.resize(MaxDepth);

        for(int i = 1; i < MaxDepth; i+= 2){
            reverse(Ans[i].begin(), Ans[i].end());
        }

        return Ans;
    }
};
*/
