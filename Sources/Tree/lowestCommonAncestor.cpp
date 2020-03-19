class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果root 为空 或 root == p 或root == q 说明root就是公共结点
        if (root == NULL || root == p || root == q) return root;
        //在左子树中找公共结点
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        //在右子树中找公共结点
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 如果左子树为空说明 公共父节点在右侧
        if (left == NULL) return right;
        // 如果右子树为空 说明公共父节点在左侧
        if (right == NULL) return left;
        //均不符合说明公共结点为root
        return root;
    }
};
