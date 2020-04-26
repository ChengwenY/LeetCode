/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }

    bool helper(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (root == NULL) return true;
        if (min != NULL && root->val <= min->val) return false;
        if (max != NULL && root->val >= max->val) return false;
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
};
