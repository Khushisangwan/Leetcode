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
    unordered_set<int> set;

    bool helper(TreeNode* node, int k) {
        if (!node) return false;

        if (set.count(k - node->val)) {
            return true;
        }

        set.insert(node->val);

        return helper(node->left, k) || helper(node->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        return helper(root, k);
    }
};