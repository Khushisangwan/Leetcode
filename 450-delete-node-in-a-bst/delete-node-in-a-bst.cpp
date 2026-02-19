class Solution {
public:
    TreeNode* findsuccessor(TreeNode* node){
        if(node==NULL) return NULL;
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            // Case 1: Leaf node
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            // Case 2: One child
            else if(root->left == NULL){
                return root->right;
            }
            else if(root->right == NULL){
                return root->left;
            }
            // Case 3: Two children
            else{
                TreeNode* successor = findsuccessor(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;   // ⭐ FIX
    }
};
