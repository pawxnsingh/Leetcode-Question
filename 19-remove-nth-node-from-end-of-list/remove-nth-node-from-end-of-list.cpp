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
class Solution{
private:
    int lengthLL(ListNode* head)
    {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        int length = lengthLL(head) - n;

        ListNode* temp = dummy;
        while(length--)
        {
            temp = temp ->next;
        }
        temp -> next = temp -> next -> next;
        return dummy -> next;
    }
};