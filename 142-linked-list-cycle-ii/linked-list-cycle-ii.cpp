class Solution {
public:
    ListNode *detectCycle(ListNode *head){
        // see 
        if(head == NULL || head -> next == NULL) return NULL;
        // see the constraint where it is very clear
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast-> next != NULL)
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