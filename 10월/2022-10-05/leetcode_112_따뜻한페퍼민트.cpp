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
private:
    bool answer = false;
    int  sum = 0;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        visit(root, &targetSum);
        return answer;
    }
    
    void visit(TreeNode* root, int* targetSum){
        if(root == nullptr) return;
        
        sum += root->val;
        
        // if leaf node
        if(root->left == nullptr && root->right == nullptr && sum == *targetSum){
            answer = true;
        }
        
        if(root->left != nullptr) visit(root->left, targetSum);
        if(root->right != nullptr) visit(root->right, targetSum);
        
        sum -= root->val;
    }
};