#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int modified_height(TreeNode* root){
        if(root == NULL) return 0;

        int left_height = modified_height(root->left);
        if( left_height == -1) return -1;

        int right_height = modified_height(root->right);
        if( right_height == -1) return -1;

        if(abs(left_height - right_height) > 1) return -1;
        return 1 + max(left_height, right_height);
    }


    bool isBalanced(TreeNode* root){
        return modified_height(root) != -1;
    }
};