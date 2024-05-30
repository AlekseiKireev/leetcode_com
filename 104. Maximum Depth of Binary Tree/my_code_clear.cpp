class Solution {

private:

int MaximumDepth = 0; 

void travel(TreeNode* Root, int height = 1){

  if(Root == nullptr){return;}

  MaximumDepth = max(MaximumDepth, height );

  travel(Root->left, height + 1);
  // MaximumDepth = max(MaximumDepth, height );   // good!
  travel(Root->right, height + 1);

  // MaximumDepth = max(MaximumDepth, height );   // good!

}

public:
    int maxDepth(TreeNode* root) {
        travel(root);
        return MaximumDepth;
    }
};
