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
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* ptr, *cptr;
        if (l1->val <= l2->val) {
            ptr = l1;
            l1 = l1->next;
        } 
        else {
            ptr = l2;
            l2 = l2->next;
        }
        
        cptr = ptr;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cptr->next = l1;
                cptr = cptr->next;
                l1 = l1->next;
            }
            else {
                cptr->next = l2;
                cptr = cptr->next;
                l2 = l2->next;
            }
        }
        
        if (l1) {
            cptr->next = l1;   
        }
        else if (l2) {
            cptr->next = l2;
        }
        return ptr;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *temp = NULL, *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        ListNode* l1 = sortList(head), *l2 = sortList(slow);
        return merge(l1, l2);
    }
};