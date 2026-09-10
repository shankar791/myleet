class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {
            int n = q.size();

            unsigned long long first = q.front().second;
            unsigned long long last = first;

            for (int i = 0; i < n; i++) {
                auto [node, index] = q.front();
                q.pop();

                // Normalize indices to avoid overflow
                index -= first;

                last = index;

                if (node->left)
                    q.push({node->left, 2 * index + 1});

                if (node->right)
                    q.push({node->right, 2 * index + 2});
            }

            ans = max(ans, last + 1);
        }

        return (int)ans;
    }
};