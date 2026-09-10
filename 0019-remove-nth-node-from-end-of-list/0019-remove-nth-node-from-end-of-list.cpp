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
        ListNode* last = head;
        ListNode* blast = nullptr;
        ListNode* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            n--;
            if (n <= 0) {
                blast = last;
                last = last->next;
            }
        }

        if (blast == nullptr) {
            head = head->next;
        } else {
            blast->next = last->next;
        }

        delete last;
        return head;
    }
};