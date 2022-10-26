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
    int cnt = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        
        int ret = kthSmallest(root->left, k);
        if (ret != -1) return ret;
        
        if (++cnt == k) return root->val;
        
        ret = kthSmallest(root->right, k);
        return ret;
    }
};