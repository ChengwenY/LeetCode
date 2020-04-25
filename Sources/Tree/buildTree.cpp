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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir) {
        if (pl > pr || il > ir) return NULL;
        int rootVal = preorder[pl];
        TreeNode *root = new TreeNode(rootVal);
        root->left = NULL;
        root->right = NULL;

        int middle = il;
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == rootVal) {
                middle = i;
                break;
            }
        }
        root->left = helper(preorder, inorder, pl+1, pl+middle-il, il, middle-1);
        root->right = helper(preorder, inorder, pl+middle-il+1, pr, middle+1, ir);
        return root;
    }
};
