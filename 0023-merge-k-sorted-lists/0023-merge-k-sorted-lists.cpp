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

/*
    Merge sort should be fast for already sorted lists
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        int i = 0;
        while (i < lists.size() - 1) {
            lists.push_back(mergeLists(lists[i], lists[i+1]));
            i+=2;

            if (i == lists.size() - 2) {
                return mergeLists(lists[i], lists[i+1]);
            }
        }
        return lists[i];
    }

    /*
        Firstly I am going to create new nodes for the new sorted list, If it    
        exceeds space complexity, I would use existing nodes to fit, otherwise I 
        will create new node for time complexity fit.
    */
    ListNode *mergeLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr || l2 == nullptr) {
            return l1 == nullptr ? l2 : l1;
        }

        ListNode *smaller = l1->val < l2->val ? l1 : l2;
        ListNode *root = smaller;
        ListNode *tail = smaller;
        
        
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr || l2 == nullptr) {
                tail->next = (l1 != nullptr ? l1 : l2);
                return root;                
            }

            bool isFirstSmaller = (l1->val < l2->val); 
            smaller = isFirstSmaller ? l1 : l2;
            ListNode *next = smaller->next;
            tail = push_back(tail, smaller);
            
            if (isFirstSmaller) {
                l1 = next;
            } else {
                l2 = next;
            }
        }
        return root;
    }

    ListNode *push_back(ListNode *tail, ListNode *node) {
        node->next = nullptr;

        if (tail == nullptr) {
            tail = node;
            return tail;
        }

        tail->next = node;
        return tail->next;
    }
};