class Solution {
public:

    int newfun(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = newfun(root->left);
        int right = newfun(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int l = newfun(root->left);
        int r = newfun(root->right);

        if (abs(l - r) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};