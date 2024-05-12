class Solution {

private:

    long long prev_node = numeric_limits<long long>::min(); // == самый левый узел, именно так можно было бы задать ему значение по умолчанию, 
                                                            // дабы избежать использования numeric_limits, ибо если бы у val был бы тип не int а long long, 
                                                            // то так бы делать было нельзя

    bool CheckDefinition(TreeNode* root){
        
        if(root == nullptr){return true;}
        
        bool f = CheckDefinition(root->left);
        if(!f){return f;}

        if(prev_node >= root->val){return false;}
        else{prev_node = root->val;}

        bool s = CheckDefinition(root->right);
        return s;
    }


public:
    bool isValidBST(TreeNode* root) {
        return CheckDefinition(root);

    }
};

/*
class Solution {
private:
    // Предыдущее значение узла, начальное значение устанавливается как минимальное значение для long long
    long long prevNodeValue = numeric_limits<long long>::min();

    // Рекурсивная функция для проверки определения BST
    bool isBST(TreeNode* root) {
        // Если узел является пустым, возвращаем true, так как пустое поддерево считается корректным BST
        if (root == nullptr) {
            return true;
        }

        // Проверяем левое поддерево
        bool isLeftSubtreeValid = isBST(root->left);
        // Если левое поддерево не является BST, возвращаем false
        if (!isLeftSubtreeValid) {
            return false;
        }

        // Проверяем, что значение текущего узла больше, чем предыдущее значение узла
        if (prevNodeValue >= root->val) {
            return false;
        } else {
            prevNodeValue = root->val; // Обновляем предыдущее значение узла
        }

        // Проверяем правое поддерево
        return isBST(root->right);
    }

public:
    // Основная функция для проверки корректности BST
    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};

*/
