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
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next)
            return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left,right);
    }

    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(l1 && l2)
        {
            if(l1 -> val < l2 -> val)
            {
                temp -> next = l1 ;
                l1 = l1 -> next;
            }
            else
            {
                temp -> next = l2;
                l2 = l2 -> next;
            }
            temp = temp -> next;
        }
        if(l1) temp -> next = l1;
        else temp -> next = l2;
        return dummy -> next;
    }

    // ListNode* getMid(ListNode* head)
    // {
    //     ListNode* slow = head;
    //     ListNode* fast = head;
    //     while(fast && fast->next)
    //     {
    //         fast = fast -> next -> next;
    //         slow = slow -> next;
    //     }
    //     ListNode* ret = slow -> next;
    //     slow -> next = nullptr;
    //     return ret;
    // }
    ListNode* getMid(ListNode* head) {
        ListNode* midPrev = nullptr;
        while (head && head->next) {
            midPrev = (midPrev == nullptr) ? head : midPrev->next;
            head = head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};