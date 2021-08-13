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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2)
        {
            int c1 = l1->val;
            int c2 = l2->val;
            if (c1 <= c2)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while (l1)
        {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2)
        {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        return head->next;
    }
};