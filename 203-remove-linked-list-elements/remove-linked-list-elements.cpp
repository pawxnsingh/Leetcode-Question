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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* del = nullptr;

        while(curr != NULL)
        {
            if(curr -> val == val)
            {
                prev -> next = curr -> next;
                del = curr;
            }
            else
            {
                prev = curr;
            }
            curr = curr -> next;

            if(del != nullptr)
            {
                delete del;
                del = nullptr;
            }
        }

        ListNode *ret = dummy -> next;
        delete dummy;
        return ret;

    }
};