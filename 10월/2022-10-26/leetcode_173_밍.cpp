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
class BSTIterator {
private:
    stack<TreeNode*> s;
    TreeNode* obj;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* ptr = root;
        while (ptr) {
            s.push(ptr);
            ptr = ptr->left;
        }
    }
    
    int next() {
        obj = s.top();
        s.pop();
        if (obj->right) {
            TreeNode* ptr = obj->right;
            while (ptr) {
                s.push(ptr);
                ptr = ptr->left;
            }
        }
        return obj->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */