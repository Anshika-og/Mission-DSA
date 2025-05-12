class Solution {
    int moves = 0;
public:
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        moves += abs(left) + abs(right);
        return node->val + left + right - 1;
    }
};
