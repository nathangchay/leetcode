/*
  2. Add Two Numbers - Medium

  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
  Add the two numbers and return the sum as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int val = 0;
        ListNode* cur;
        
        ListNode* head = new ListNode(l1->val + l2->val + carry);
        if (head->val > 9) {
            head->val -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        
        l1 = l1->next;
        l2 = l2->next;
        
        cur = head;
        
        while (l1 != nullptr || l2 != nullptr) {
            val = 0;
            
            if (l1 == nullptr) {
                val = l2->val + carry;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                val = l1->val + carry;
                l1 = l1->next;
            } else {
                val = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            if (val > 9) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        
        if (carry == 1) {
            cur->next = new ListNode(carry);
        }
        
        return head;
    }
};