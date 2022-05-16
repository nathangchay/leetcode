/*
  21. Merge Two Sorted Lists - Easy

  You are given the heads of two sorted linked lists list1 and list2.

  Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

  Return the head of the merged linked list.
*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode();
        ListNode* cur = result;
        
        if (list1 == nullptr) {
            return list2;
        }
        
        if (list2 == nullptr) {
            return list1;
        }
        
        if (list1->val < list2->val) {
            result->val = list1->val;
            list1 = list1->next;
        } else {
            result->val = list2->val;
            list2 = list2->next;
        }
        
        while (list1 != nullptr || list2 != nullptr) {
            cur->next = new ListNode();
            cur = cur->next;
            
            if (list1 == nullptr) {
                cur->val = list2->val;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                cur->val = list1->val;
                list1 = list1->next;
            } else {
                if (list1->val < list2->val) {
                    cur->val = list1->val;
                    list1 = list1->next;
                } else {
                    cur->val = list2->val;
                    list2 = list2->next;
                }
            }
        }
        
        return result;
    }
};