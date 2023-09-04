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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head -> next == NULL) return head;
// this Question will be solved into the three phases 

        // this is the first Phase
        ListNode* dummy = new ListNode;
        dummy -> next = head;
        ListNode* lprev = dummy,*prev = NULL,*curr = head;
        for(int i=0;i<left-1;i++)
        {
            lprev = curr;
            curr = curr -> next;
        }

        for(int i=0;i<=right-left;i++)
        {
            ListNode* track = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = track;
        }
        ListNode* rprev = lprev -> next;
        lprev -> next = prev;
        rprev -> next = curr;
        return dummy -> next;
    }
};   