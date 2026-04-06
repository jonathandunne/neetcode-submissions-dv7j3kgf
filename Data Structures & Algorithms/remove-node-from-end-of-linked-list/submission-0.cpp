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
        if (!head) {
            return head;
        }
        int nodes = 1;
        ListNode* curr = head;

        while (curr->next) {
            nodes++;
            curr = curr->next;
        }

        if (!(nodes - n)) {
            return head->next;
        }

        ListNode* prev = nullptr;
        curr = head;
        int idx = 0;

        while ((nodes - n - idx)) {
            prev = curr;
            curr = curr->next;
            idx++;
        }

        prev->next = curr->next;





        return head;
    }
};
