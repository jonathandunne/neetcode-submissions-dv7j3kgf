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
        ListNode* start = new ListNode();
        ListNode* cur = start;
        int carry = 0;

        while (l1 || l2 || carry) {
            int v1 = 0;
            if (l1) {
                v1 = l1->val;
            }

            int v2 = 0;
            if (l2) {
                v2 = l2->val;
            }

            int sum = v1 + v2 + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            else {
                carry = 0;
            }

            cur->next = new ListNode(sum);
            cur = cur->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }

        ListNode* result = start->next;
        delete start;
        return result;
    }
};
