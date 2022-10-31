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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ret, ln, rn;
        if (p == NULL || q == NULL) {
            if (p == NULL && q == NULL) return true;
            else return false;
        }
        
        if (p->val != q->val) return false;
        
        if (p->left && q->left) {
            ret = isSameTree(p->left, q->left);
            if (!ret) return false;
        } 
        else if (p->left == NULL && q->left == NULL) ln = true;
        else return false;
        
        if (p->right && q->right) {
            ret = isSameTree(p->right, q->right);
            if (!ret) return false;
        }
        else if (p->right == NULL && q->right == NULL) rn = true;
        else return false;
        
        return true;
    }
};