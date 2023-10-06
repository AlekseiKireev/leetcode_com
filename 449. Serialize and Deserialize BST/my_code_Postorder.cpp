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
public:

    string serialize(TreeNode* root) {
        return Postorder(root);
    }

    TreeNode* deserialize(const string& data) { // string_view data // error!

        stringstream ss(data);        
        TreeNode* root = nullptr;
        
        for (string item; getline (ss, item, '-');) {
            root = Add(root, stoi(item));
        }
            
        return root;
    }
    
private:

    string Postorder(TreeNode* root) {
        if (!root) {return {};}       
        string val_2 = Postorder(root->left);
        string val_3 = Postorder(root->right);
        string val_1 = to_string(root->val) + "-";
        return  val_1 + val_2 + val_3;
    }
    
    TreeNode* Add(TreeNode* root, int Value) {
        
        if (root == nullptr) {return new TreeNode(Value);;}
    
		if (Value < root->val){
            root->left=Add(root->left,Value);
        }
    
		if (root->val < Value){
			root->right=Add(root->right,Value);
        }
		return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans; 
