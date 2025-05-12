class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode* node, string path, vector<string>& res) {
        if (!node) return;

        path += to_string(node->val);

        if (!node->left && !node->right) {
            res.push_back(path);
        } else {
            path += "->";
            dfs(node->left, path, res);
            dfs(node->right, path, res);
        }
    }
};
