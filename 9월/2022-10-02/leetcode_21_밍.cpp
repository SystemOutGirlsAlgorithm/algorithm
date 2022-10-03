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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr, *cptr;
        
        if (list1 == nullptr && list2 == nullptr)
            return ptr;
        else if (list1 == nullptr) 
            return list2;
        else if (list2 == nullptr)
            return list1;
        
        if (list1->val < list2->val) {
            ptr = list1;
            list1 = list1->next;
        }
        else {
            ptr = list2;
            list2 = list2->next;
        }
        
        cptr = ptr;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                cptr->next = list1;
                cptr = cptr->next;
                list1 = list1->next;
            }
            else {
                cptr->next = list2;
                cptr = cptr->next;
                list2 = list2->next;
            }
        }
        
        if (list1) {
            cptr->next = list1;   
        }
        else if (list2) {
            cptr->next = list2;
        }
        
        return ptr;
    }
};