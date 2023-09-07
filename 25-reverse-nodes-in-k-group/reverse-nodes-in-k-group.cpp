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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* groupPrev = dummy;

        while(true)
        {
            ListNode* kth = getKth(groupPrev,k);
            if(kth == NULL) break;
            groupPrev -> next = kth;
            ListNode* groupNext = kth -> next;

            ListNode*curr = head,*prev = groupNext;

            while(curr != groupNext)
            {
                ListNode*track = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = track;
            }   
            groupPrev = head;
            head = groupNext;
        }
        return dummy -> next;
    }

    ListNode* getKth(ListNode*head,int k){
        ListNode* curr = head;
        while(curr && k>0){
            curr = curr -> next;
            k--;
        }return curr;
    }


};