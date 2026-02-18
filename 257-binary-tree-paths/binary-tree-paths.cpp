class Solution {
public:

    void helper(TreeNode* root, string path, vector<string> &ans) {
        if(root == NULL) return;

        // Add current node to path
        if(path == "")
            path = to_string(root->val);
        else
            path += "->" + to_string(root->val);

        // If leaf node → store path
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        // Traverse children
        helper(root->left, path, ans);
        helper(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};
