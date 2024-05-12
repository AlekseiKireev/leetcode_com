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
/*
Каждый раз, когда вызывается метод DFS, переменная SumLeftLeaves используется для накопления суммы значений левых листьев дерева. 
Поскольку SumLeftLeaves находится в области видимости класса, она не переинициализируется при каждом вызове метода DFS. 
Вместо этого она сохраняет свое значение между вызовами метода DFS.

Таким образом, при каждом рекурсивном вызове метода DFS значение SumLeftLeaves увеличивается на значение root->val, если текущий узел является левым листом. 
В итоге SumLeftLeaves содержит сумму значений всех левых листьев дерева после завершения рекурсии.
*/
    int SumLeftLeaves = 0; // в каждый рекурсивный вызов передается ССЫЛКА на эту переменную и в нее накапливается сумма

    void DFS(TreeNode* root, bool IsLeftChild){ //DFS == preoder

        if(root == nullptr){return;} 

        // check on left leave
        if(IsLeftChild && 
        root->left == nullptr && 
        root->right == nullptr
        ){ // 2 и 3 аргумент -- проверка на то, что node -- лист. 1 аргумент проверряет, что лист левый.
            SumLeftLeaves += root->val;}

        DFS(root->left, true);
        DFS(root->right, false);
    }

public:

    int sumOfLeftLeaves(TreeNode* root) {
        
        DFS(root, false); // "false" ввиду "Example 2"
        return SumLeftLeaves;
    }
};

/*
class Solution {

    int DFS(TreeNode* root, bool IsLeftChild){ //DFS == preoder

        if(root == nullptr){return 0;} 

        // check on left leave
        if(IsLeftChild && 
        root->left == nullptr && 
        root->right == nullptr
        ){ // 2 и 3 аргумент -- проверка на то, что node -- лист. 1 аргумент проверряет, что лист левый.
            return root->val;}

        return DFS(root->left, true) + DFS(root->right, false);
    }

public:

    int sumOfLeftLeaves(TreeNode* root) {
               
        return DFS(root, false); // "false" ввиду "Example 2"
    }
};
*/

//-------------------------------------------------------------------------

/*
class Solution {

int SUM = 0;

void travel(TreeNode* node, bool IsLeft, int& Sum){

    if(node == nullptr){return;} 
    bool IsLeaf = (node->left == nullptr && node->right == nullptr);
    if(IsLeaf && IsLeft){
        Sum += node->val;
    }
    travel(node->left, true, Sum);
    travel(node->right, false, Sum);

}

public:
    int sumOfLeftLeaves(TreeNode* root) {
        travel(root, false, SUM);
        return SUM;
    }
};
*/
