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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* evenhead = head->next;
        ListNode* oddptr = head, *evenptr = evenhead;
        
        while (evenptr != nullptr) {
            oddptr->next = oddptr->next->next;
            if (evenptr->next != nullptr) evenptr->next = evenptr->next->next; else break;
            oddptr = oddptr->next;
            evenptr = evenptr->next;
        }
        
        oddptr->next = evenhead;
        return head;
    }
};