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
    TreeNode* sortedArrayToBST(vector<int>& nums, int first, int last) {
        if (first > last) return NULL;
        int mid = (first + last) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, first, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, last);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
};