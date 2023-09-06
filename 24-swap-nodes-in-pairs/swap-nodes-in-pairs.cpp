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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* dummy = new ListNode;
        dummy -> next = head;
        
        ListNode* prev = dummy,*curr = head;

        while(curr != NULL && curr -> next != NULL)
        {
            // save part of next pair
            ListNode* nxtpair = curr -> next -> next;
            ListNode* second = curr -> next;
            // reverse this pair
            second-> next = curr;
            curr -> next  = nxtpair;
            prev -> next = second;
            // update ptr
            prev = curr;
            curr = nxtpair;
        }
        return dummy->next;
    }
};