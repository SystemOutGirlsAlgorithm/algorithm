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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* p = head, *prev = NULL, *tmp = NULL;
        
        while (p != nullptr) {     
            prev = tmp;
            tmp = p;
            p = p->next;
            
            tmp->next = prev;
        }
        
        return tmp;
    }
};