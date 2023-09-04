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
    void reorderList(ListNode* head){
        if(head -> next == NULL) return;
        // find the Middle
        ListNode*slow = head,*fast = head;
        while(fast && fast->next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // slow is my mid and head where i have to start the reversal Process
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL)
        {
            ListNode* track = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = track;
        }

        // ListNode*first = head,*second = prev,*temp;
        // while(first ->next != NULL)
        // {
        //     temp -> next = first;
        //     first = first -> next;
        //     temp = temp -> next;

        //     temp -> next = second;
        //     second = second -> next;
        //     temp = temp -> next;
        // }


        ListNode* first = head, *second = prev,*tmp;
        while (second -> next != NULL) {
            tmp = first->next;
            first -> next = second;
            first = tmp;

            tmp = second -> next;
            second -> next = first;
            second = tmp;
        }
    }
};