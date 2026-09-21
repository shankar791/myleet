class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({root->left, root->right});

        while (!q.empty()) {
            auto [left, right] = q.front();
            q.pop();

            // Both are NULL
            if (left == nullptr && right == nullptr)
                continue;

            // Only one is NULL
            if (left == nullptr || right == nullptr)
                return false;

            // Values are different
            if (left->val != right->val)
                return false;

            // Compare mirror children
            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }

        return true;
    }
};