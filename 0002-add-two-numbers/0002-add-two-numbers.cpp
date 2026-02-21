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
        int a=0; int q=0; int r=0;
        ListNode *node = NULL;
        ListNode *root = NULL;
        while (l1 != NULL || l2 != NULL || q != 0) {
            a = q;
            if (l1 != NULL) a += l1->val;
            if (l2 != NULL) a += l2->val;
            r = a % 10;
            q = a / 10;
            
            ListNode *new_node = new ListNode(r);
            if (node != NULL) node->next = new_node;
            if (node == NULL) root = new_node;
            node = new_node;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        return root;
    }

    int pow(int n, int p) {
        if (p<=0) {
            return 1;
        }
        return n * pow(n, p-1);
    }
};