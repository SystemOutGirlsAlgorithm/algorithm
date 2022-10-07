/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode* ptr = head;
        
        while (ptr != nullptr) {
            if (s.insert(ptr).second == false) {
                return ptr;
            }
            else {
                ptr = ptr->next;
            }
        }
        
        return nullptr;
    }
};