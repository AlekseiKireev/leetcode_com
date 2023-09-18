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

private:

int Travel(TreeNode* node, int Height = 0){
  
  
  if(node == nullptr){return Height;}
  ++Height; // высота текущего узла
  
  int LeftHeight = Travel(node->left, Height);
  if(LeftHeight == -1){return -1;}

  int RightHeight = Travel(node->right, Height);
  if(RightHeight == -1){return -1;}

  cout << LeftHeight << ' ' << RightHeight << '\n';
  if(abs(RightHeight - LeftHeight) > 1){return -1;}

  return max(LeftHeight, RightHeight) + 1;
}

public:
    bool isBalanced(TreeNode* root) {
      
      if(root == nullptr){return true;}
      return (Travel(root->left)  >= 0 && Travel(root->right) >= 0);

    }
};
