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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1, *ptr2 = l2;
        int n = 0, sum = 0;
        ListNode* ans = new ListNode(-1), *ptr = ans; 

        while (true) {
            sum = 0;
            if (ptr1 != NULL) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2 != NULL) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }
            sum += n;
            n = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            ptr->next = node;
            ptr = ptr->next;
            if (ptr1 == nullptr && ptr2 == nullptr && n == 0) break;
        }
        return ans->next;
    }
};