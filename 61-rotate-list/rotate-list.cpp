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
    ListNode* rotateRight(ListNode* head, int k){
        if(head == NULL || head -> next == NULL) return head;

        ListNode* tail = NULL;
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL)
        {
            length++;
            tail = temp;
            temp = temp -> next;
        }

        k = k % length;
        if(k == 0)
            return head;
        
        temp = head;
        for(int i=1;i<length-k;i++)
        {
            temp = temp -> next;
        }
        ListNode* sHead = temp -> next;
        temp -> next = NULL;
        tail -> next = head;
        head = sHead;
        return head;
    }
};