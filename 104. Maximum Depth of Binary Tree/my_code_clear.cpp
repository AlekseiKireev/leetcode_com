class Solution {

private:

int MaximumDepth = 0; 

void travel(TreeNode* Root, int height = 1){

  if(Root == nullptr){return;}

  MaximumDepth = max(MaximumDepth, height );

  travel(Root->left, height + 1);

  travel(Root->right, height + 1);

}

public:
    int maxDepth(TreeNode* root) {
        travel(root);
        return MaximumDepth;
    }
};
