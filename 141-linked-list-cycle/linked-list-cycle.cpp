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
    bool hasCycle(ListNode *head){
        if(head == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast)
        {
            if(fast == NULL || fast->next == NULL) 
                return false;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        // we can write as well
        // while(fast && fast->next)
        // {
        //     slow = slow -> next;
        //     fast = fast -> next -> next;
        //     if(fast == slow) return true;
        // }
        // return false;
        return true;
    }
};