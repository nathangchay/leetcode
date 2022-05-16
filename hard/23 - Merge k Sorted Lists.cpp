/*
  23. Merge k Sorted Lists - Hard

  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

  Merge all the linked-lists into one sorted linked-list and return it.
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
    bool nonEmptyListExists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        for (int i = 0; i < n; i++) {
            if (lists[i] != nullptr) {
                return true;
            }
        }
        
        return false;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* result = new ListNode();
        ListNode* cur = result;
        ListNode* min_el;
        int min_el_ind;
        
        if (lists.empty() || !nonEmptyListExists(lists)) {
            return nullptr;
        }
        
        min_el_ind = 0;
        min_el = lists[min_el_ind];
        while (min_el == nullptr) {
            min_el_ind++;
            min_el = lists[min_el_ind];
            
            if (min_el_ind >= n) {
                break;
            }
        }
        
        for (int i = min_el_ind + 1; i < n; i++) {
            if (lists[i] == nullptr) {
                    continue;
            }
            
            if (lists[i]->val < min_el->val) {
                min_el = lists[i];
                min_el_ind = i;
            }
        }
        
        result->val = min_el->val;
        lists[min_el_ind] = lists[min_el_ind] -> next;
        
        while (nonEmptyListExists(lists)) {
            cur->next = new ListNode();
            cur = cur->next;
            
            min_el_ind = 0;
            min_el = lists[min_el_ind];
            while (min_el == nullptr) {
                min_el_ind++;
                min_el = lists[min_el_ind];
            }
            
            for (int i = min_el_ind + 1; i < n; i++) {
                if (lists[i] == nullptr) {
                    continue;
                }
                
                if (lists[i]->val < min_el->val) {
                    min_el = lists[i];
                    min_el_ind = i;
                }
            }
            
            cur->val = min_el->val;
            cout << "Before: " << min_el->val << " "; 
            lists[min_el_ind] = lists[min_el_ind]->next;
            cout << "After: " << min_el->val << endl;
        }
        
        return result;
    }
};