class Solution {

  int getHeight(TreeNode* node, int &ans) {
    if (node == nullptr) { 
      return -1;
    }
    int leftH = getHeight(node->left, ans) + 1; 
    int rightH = getHeight(node->right, ans) + 1; 
    int path = leftH + rightH;
    ans = max(ans, path);
    return max(leftH, rightH);
  }

public:

  int diameterOfBinaryTree(TreeNode* root) { 
    int ans = 0;
    getHeight(root, ans);
    return ans;
  }
};
