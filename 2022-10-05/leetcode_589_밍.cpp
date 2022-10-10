/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:    
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        res.push_back(root->val);
        for (auto i: root->children) {
            vector<int> tmp = preorder(i);
            for (auto j: tmp) {
                res.push_back(j);
            }
        }
        return res;
    }
};