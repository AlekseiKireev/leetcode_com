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

  string Postorder(TreeNode* Node){ 

      if(Node == nullptr){return {};} // https://stackoverflow.com/questions/26587110/returning-an-empty-string-efficient-way-in-c

      string LeftBranch = Postorder(Node->left);
      string RightBranch = Postorder(Node->right);

      string Subtree = to_string(Node->val) + '*'+ LeftBranch+ '#'+ RightBranch;

       if(++SubtreeToCount[Subtree] == 2){DuplicateSubtrees.push_back(Node);} // good!
      //if(SubtreeToCount[move(Subtree)]++ == 1){DuplicateSubtrees.push_back(Node);} // error: если элемент не сущесвует в мапине, то он создастся и при этом данные из строки будет перемещены. А вы потом эту строку возвращаете. А в первом случае со строкой никаких метаморфоз не произойдет

      return Subtree;
      /*
Киреев Алексей MonsieurAKA, [9/28/2023 1:37 PM]
а тогда move можно в return засунуть, или это так не работает?

return move(Subtree); // речь об этом, оптимизация будет? Если нет, можно как-то ее получить?

Alexander "Ternvein" Isaev, [9/28/2023 1:38 PM]
С move не будет, без move — будет.

Киреев Алексей MonsieurAKA, [9/28/2023 1:40 PM]
а почему так, можно подробнее?

Alexander "Ternvein" Isaev, [9/28/2023 1:40 PM]
Почитайте про NRVO.
Если коротко: return move(...) — это всегда деградация.
      */
  }

public:

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        Postorder(root);

        return DuplicateSubtrees;

    }
};
