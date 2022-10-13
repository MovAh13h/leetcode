/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast = head;
        ListNode * slow = head;
        
        if (head == nullptr) {
            return nullptr;
        }
        
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            
            if (fast == nullptr) {
                return nullptr;
            } else {
                fast = fast->next;
            }
            
            if (slow == fast) {
                break;
            }
        }
        
        if (fast == nullptr) {
            return nullptr;
        }
        
        slow = head;
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};