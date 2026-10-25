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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
}
        if (root->left == nullptr&&root->val > val) {
        TreeNode* temp = new TreeNode(val);
        root->left = temp;
        return root;
    }
    else if (root->val < val && root->right == nullptr) {
        TreeNode* temp = new TreeNode(val);
        root->right = temp;
        return root;
    }

    if (root->val > val) {
        insertIntoBST(root->left, val);
    }
    else {
        insertIntoBST(root->right, val);
    }

    return root;
}


};