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
    ListNode* middleNode(ListNode* head) {
        ListNode * temp = head, * prev = head;
        
        while (temp != nullptr) {
            if (temp == head) {
                prev = head;
                temp = temp->next;
                continue;
            }
            
            prev = prev->next;
            temp = temp->next;
            if (temp != nullptr) 
                temp = temp->next;
        }
        
        return prev;
    }
};