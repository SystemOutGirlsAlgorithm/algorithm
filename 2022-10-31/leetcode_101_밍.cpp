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
    vector<int> left;
    vector<int> right;
    void dfsleft(TreeNode* node) {
        if (!node) left.push_back(-1000);
        else {
            left.push_back(node->val);
            dfsleft(node->left);
            dfsleft(node->right);
        }
    }
    
    void dfsright(TreeNode* node) {
        if (!node) right.push_back(-1000);
        else {
            right.push_back(node->val);
            dfsright(node->right);
            dfsright(node->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root->left && root->right) {
            dfsleft(root->left);
            dfsright(root->right);
            if (left == right) return true;
            else return false;
        }
        else if (!root->left && !root->right) return true;
        else return false;
    }
};