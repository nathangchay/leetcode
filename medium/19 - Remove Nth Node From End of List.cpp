/*
  19. Remove Nth Node From End of List - Medium

  Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int size = 1;
        
        while (cur->next != nullptr) {
            size++;
            cur = cur->next;
        }
        
        if (size == n) {
            if (head->next != nullptr) {
                return head->next;
            } else {
                return nullptr;
            }
        }
        
        cur = head;
        
        for (int i = 0; i < size - n - 1; i++) {
            cur = cur->next;
        }
        
        cur->next = cur->next->next;
        
        return head;
    }
};