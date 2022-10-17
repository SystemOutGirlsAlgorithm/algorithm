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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prevptr, *ptr = head, *nextptr = head; 
        for (int m = 0; m < n; m++) nextptr = nextptr->next;
        
        while (nextptr != nullptr) {
            prevptr = ptr;
            ptr = ptr->next;
            nextptr = nextptr->next;
        }
        
        if (ptr->next != nullptr) { 
            if (prevptr == nullptr) // remove first element
                head = head->next;
            else // remove middle element
                prevptr->next = ptr->next;
        }
        else { // remove last element
            if (prevptr == nullptr) // size = 1
                head = nullptr;
            else if (prevptr->next != nullptr) // size > 2
                prevptr->next = nullptr;
            else
                head->next = nullptr; // size = 2
        }
        return head;
    }
};