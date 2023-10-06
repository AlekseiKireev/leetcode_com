/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

private:

TreeNode* Add(TreeNode* Node, int Value){
    
    if(Node == nullptr){return (new TreeNode(Value));}

    if(Value < Node->val){Node->left = Add(Node->left, Value);}
    if(Node->val < Value){Node->right = Add(Node->right, Value);}

    return Node;

}


string Preorder(TreeNode* root){
    if(root == nullptr){return {};}
    return (to_string(root->val) + "-" + Preorder(root->left) + Preorder(root->right));
}

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return Preorder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        TreeNode* Root = nullptr;
        for(string Value; getline(ss, Value, '-');){
            Root = Add(Root, stoi(Value));
        }

        return Root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
