#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Returns height if balanced, -1 if unbalanced
    int modified_height(TreeNode* root){
        // Base case: empty tree has height 0
        if(root == NULL) return 0;

        // Check left subtree height
        int left_height = modified_height(root->left);
        if(left_height == -1) return -1; // Left subtree is unbalanced

        // Check right subtree height
        int right_height = modified_height(root->right);
        if(right_height == -1) return -1; // Right subtree is unbalanced

        // Current node is unbalanced if height difference > 1
        if(abs(left_height - right_height) > 1) return -1;
        
        // Return height of balanced tree
        return 1 + max(left_height, right_height);
    }

    // Check if binary tree is balanced
    bool isBalanced(TreeNode* root){
        return modified_height(root) != -1;
    }
};