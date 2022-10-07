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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        
        
        vector<int> minres;
        int level = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* ptr = q.front().first;
            if (level < q.front().second) {
                res.push_back(minres);
                minres.clear();
                level = q.front().second;
            }
            q.pop();
            
            minres.push_back(ptr->val);
            if (ptr->left != NULL) {
                q.push({ptr->left, level + 1});
            }
            if (ptr->right != NULL) {
                q.push({ptr->right, level + 1});
            }
        }
        
        res.push_back(minres);
        return res;
    }
};