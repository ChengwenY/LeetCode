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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int level = 0;
        helper(res, root, level);
        return res;
    }

    void helper(vector<vector<int>> &res, TreeNode *root, int level) {
        if (!root) return;
        if (level == res.size()) {
            res.push_back({});
        } 
        // vector<int> &subRes = res[level]; 注意如果取出res中的元素需要加取地址符 否则subRes只是一份拷贝 不是引用
        if (level%2==0) {
            res[level].push_back(root->val);
        } else {
            res[level].insert(res[level].begin(),root->val);
        }
        helper(res, root->left, level+1);
        helper(res, root->right, level+1);
    }
};