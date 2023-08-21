class Solution {

  // решение проходит по вершинам в порядке preorder
  void visit(
    TreeNode* node,
    TreeNode* p,
    TreeNode* q,
    bool &pFound,
    bool &qFound,
    TreeNode*& lca
  ) {
    
    if (node == nullptr) {return;}
    
    if (pFound && qFound) {return;}

    // у переменной foundBefore положение фиксированное, находится в preorder-обходе, выше условных операторов в которых изменяется pFound / qFound
    // ввиду того, чтобы node = p или node = q мог быть ответом -- см. "Example 2:"
    bool foundBefore = pFound || qFound; // было ли хоть что-то найдено до этого [выше / в ином поддереве]. 
                                         // Если да, то текущая [распаложенная ниже / в ином поддереве ранее найденной] вершина LCA быть не может
    
    if (node == p) {pFound = true;}
    if (node == q) {qFound = true;}
    
    visit(node->left, p, q, pFound, qFound, lca);

    // good!
    /*
    if (node == p) {pFound = true;}
    if (node == q) {qFound = true;}
    */
    
    // error: хорошо видно это на данных из "Example 2:"
    // if (lca == nullptr && pFound && qFound && !foundBefore) { lca = node;}
    
    visit(node->right, p, q, pFound, qFound, lca);

    // good!
    /*
    if (node == p) {pFound = true;}
    if (node == q) {qFound = true;}
    */

    // "lca == nullptr" необходим для того, чтобы гарантировать "Lowest" -- иначе вернется корень дерева
    if (lca == nullptr && pFound && qFound && !foundBefore) { lca = node;} // стек рекурсивных вызовов раскручивается до тех пор, пока определение foundBefore не станет равным false
  }

public:


  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { 
    
    assert(p != nullptr);
    assert(q != nullptr); 
    assert(p != q);
    
    bool pFound = false; 
    bool qFound = false; 
    TreeNode* lca = nullptr;
    
    visit(root, p, q, pFound, qFound, lca);
    
    assert(lca != nullptr); 
    return lca;
    }
  };
