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

vector<vector<int>> ZigzagLevel; // map : height --> nodes at this height

void Visited(TreeNode* node, int Height){

    if(node == nullptr){return;}

    // можно использовать условный оператор вместо цикла по той причине, что для каждого рекур-о вызова сразу же проверяем Height --> не возникнет ситуации
    // Height > ZigzagLevel.size() [что будет продемонстр-о в inorder / postorder], единственное, чтто может быть: Height == ZigzagLevel.size()
    
    if(Height == ZigzagLevel.size()){ZigzagLevel.push_back(vector<int>());} /* <--> */ // while(Height >= ZigzagLevel.size()){ZigzagLevel.push_back(vector<int>());} 
    assert(Height < ZigzagLevel.size());
    ZigzagLevel[Height].push_back(node->val);

    cout <<  Height << " : " << node-> val <<'\n'; // см. вывод ниже для root = [3,9,20,18,21,4,15,7]
    
    Visited(node->left, Height + 1);
    Visited(node->right, Height + 1);
}

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        Visited(root, 0);
        return ZigzagLevel;
    }
};
/*
0 : 3
1 : 9
2 : 18
3 : 7
2 : 21
1 : 20
2 : 4
2 : 15
*/
