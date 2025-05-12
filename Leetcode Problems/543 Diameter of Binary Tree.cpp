class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfs(root, diameter);
        return diameter;
    }

    int dfs(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int left = dfs(node->left, diameter);
        int right = dfs(node->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
};
