/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* ptr = head;
        vector<ListNode*> v;
        while (ptr != nullptr) {
            v.push_back(ptr);
            ptr = ptr->next;
        }
        
        int left = 0, right = v.size()-1;
        while (left < right) {
            if (v[left++]->val != v[right--]->val)
                return false;
        }
        
        return true;
    }
};