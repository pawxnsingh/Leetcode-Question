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
        if(head == NULL || head -> next == NULL) return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;


        while(slow != NULL && fast != NULL && fast-> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow) break;
        }
        
        ListNode *entry = head;
        while(entry != NULL && slow != NULL )
        {
            if(slow == entry) return entry;
            slow = slow-> next;
            entry = entry -> next;
        }
        return NULL;
    }
};