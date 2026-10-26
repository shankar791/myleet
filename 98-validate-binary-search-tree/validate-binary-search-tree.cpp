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
    bool checkLeft(TreeNode* root, int val) {
        if (root == nullptr) {
            return true;
        }

        if (root->val >= val) {
            return false;
        }

        return checkLeft(root->left, val) &&
               checkLeft(root->right, val);
    }

    bool checkRight(TreeNode* root, int val) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= val) {
            return false;
        }

        return checkRight(root->left, val) &&
               checkRight(root->right, val);
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!checkLeft(root->left, root->val) ||
            !checkRight(root->right, root->val)) {
            return false;
        }

        return isValidBST(root->left) &&
               isValidBST(root->right);
    }
};
