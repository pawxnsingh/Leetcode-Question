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

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        while(head && head -> next)
        {
            // node to be reversed
            ListNode* firstNode = head;
            ListNode* secondNode = head -> next;

            // node to be reversed
            firstNode -> next = secondNode -> next;
            secondNode -> next = firstNode;
            prev -> next = secondNode;

            //
            prev = firstNode;
            head = firstNode -> next;
        }
        return dummy->next;
    }
};