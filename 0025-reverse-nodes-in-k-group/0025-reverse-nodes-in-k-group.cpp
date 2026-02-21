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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *start, *old_start, *tail;
        bool not_complete = false, is_first = true;
        int total=0;

        while (true) {
            start = get_next(head, total, not_complete);
            tail = get_next(start, k-1, not_complete);
            total += k;

            if (not_complete) {
                return head;
            }
            
            if (is_first) {
                head = tail;
                is_first = false;
            }
            else {
                old_start->next = tail;
            }
            
            reverse(start, tail, k);
            old_start = start;
        }   
        return start;
    }

    void reverse(ListNode *head, ListNode* tail, int k) {
        ListNode *next = head->next;        
        for (int i=0; i<k-1; i++){
            head->next = tail->next;
            tail->next = head;
            head = next;
            next = head->next;
        }
    }

    ListNode *get_next(ListNode *head, int k, bool &not_complete) {
        while(k--) {
            if (head->next == nullptr) {
                not_complete = true;
                return head;
            }
            head = head->next;
        }
        return head;
    }
};