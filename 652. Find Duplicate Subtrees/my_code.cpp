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

  vector<TreeNode*> DuplicateSubtrees;
  unordered_map<string, int> SubtreeToCount;

private:

  string Postorder(TreeNode* Node){ // обходит дерево от листьев к родителем листьев и т.д. выше

      if(Node == nullptr){return {};}

      string LeftBranch = Postorder(Node->left);
      string RightBranch = Postorder(Node->right);

      string Subtree = to_string(Node->val) + ' '+ LeftBranch+ ' '+ RightBranch;

       if(SubtreeToCount[Subtree]++ == 1){DuplicateSubtrees.push_back(Node);} // good!
      //if(++SubtreeToCount[move(Subtree)] == 2){DuplicateSubtrees.push_back(Node);}
      // else{++SubtreeToCount[move(Subtree)];} // Wrong Answer 133 / 175 testcases passed Input root = [1,2,3,4,null,2,4,null,null,4] Output [[4],[2,4],[4]] Expected [[2,4],[4]]

      //++SubtreeToCount[move(Subtree)]; // <-- T& operator[]( Key&& key ); (2)	(since C++11) <-- https://en.cppreference.com/w/cpp/container/unordered_map/operator_at
      return Subtree;
  }

public:

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        Postorder(root);

        return DuplicateSubtrees;

    }
};
