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

int MaximumDepth = 0; // подсчет высоты происходит сверху вниз, в то время как в my_code_rec_int.cpp -- снизу вверх

void travel(TreeNode* Root, int height = 0){

  if(Root == nullptr){return;}

  height += 1; // перефраз задачи: просят найти максимальную глубину рекурсии
  //cout << "height: " << height << '\n';
  MaximumDepth = max(MaximumDepth, height);

  travel(Root->left, height);
  /* Wrong Answer 13 / 39 testcases passed Editorial Input root = [1,2] Use Testcase Output 1 Expected 2
    height += 1; // перефраз задачи: просят найти максимальную глубину рекурсии
  // cout << "height: " << height << '\n';
  MaximumDepth = max(MaximumDepth, height);
  */
  travel(Root->right, height);

}

public:
    int maxDepth(TreeNode* root) {
        travel(root);
        return MaximumDepth;
    }
};

/*
class Solution {

void travel(TreeNode* root, int& MaximumDepth, int height = 0){

    if(root == nullptr){return;}
    ++height;
    MaximumDepth = max(MaximumDepth, height);
    travel(root->left, MaximumDepth, height);
    travel(root->right, MaximumDepth, height);
}

public:
    int maxDepth(TreeNode* root) {
        int max = 0;
        travel(root, max);
        return max;
    }
};
*/
