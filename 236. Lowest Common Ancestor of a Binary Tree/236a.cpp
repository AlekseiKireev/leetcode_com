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
    
    bool foundBefore = pFound || qFound; // было ли хоть что-то найдено до этого [выше / в ином поддереве]. 
                                         // Если да, то текущая [распаложенная ниже / в ином поддереве ранее найденной] вершина LCA быть не может
    
    if (node == p) {pFound = true;}
    if (node == q) {qFound = true;}
    
    visit(node->left, p, q, pFound, qFound, lca);
    visit(node->right, p, q, pFound, qFound, lca);
    
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
