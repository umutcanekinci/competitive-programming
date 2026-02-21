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
        ListNode *root = nullptr;
        ListNode *tail = nullptr;
        ListNode *smaller;
        
        while(l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr || l2 == nullptr) {
                ListNode *notEmpty = l1 != nullptr ? l1 : l2;
                if (root == nullptr) {
                    return notEmpty;
                } else {
                    tail->next = notEmpty;
                }
                return root;
            }

            bool isFirstSmaller = (l1->val < l2->val); 
            smaller = isFirstSmaller ? l1 : l2;
            ListNode *next = smaller->next;
            tail = push_back(tail, smaller);
            if (root == nullptr) {
                root = tail;
            }
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