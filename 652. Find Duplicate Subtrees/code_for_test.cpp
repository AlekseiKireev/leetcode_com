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
    vector<TreeNode*> ans;
    unordered_map<string, int> count;
    vector<string> OrderPush;

 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

    encode(root);

    for(string& str : OrderPush){
        cout << str << '\n';
    }

    return ans;
  }

 private:

  string encode(TreeNode* root) {

    if (root == nullptr) {return "";}

    const string encoded = to_string(root->val) + "#" + encode(root->left) + "*" + encode(root->right) + "|"; // postorder !!!
    
    cout << root->val << '\n';

    OrderPush.push_back(encoded);
    if (++count[encoded] == 2) {ans.push_back(root);}
    
    return encoded;
  }

};
/*
[25,15,50,10,22,35,70,4,12,18,24,31,44,66,90]

4
12
10
18
24
22
15
31
44
35
66
90
70
50
25
4#*|
12#*|
10#4#*|*12#*||
18#*|
24#*|
22#18#*|*24#*||
15#10#4#*|*12#*||*22#18#*|*24#*|||
31#*|
44#*|
35#31#*|*44#*||
66#*|
90#*|
70#66#*|*90#*||
50#35#31#*|*44#*||*70#66#*|*90#*|||
25#15#10#4#*|*12#*||*22#18#*|*24#*|||*50#35#31#*|*44#*||*70#66#*|*90#*||||
*/
