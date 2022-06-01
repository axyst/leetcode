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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right) return head;
        ListNode *first = nullptr;
        ListNode *cur = head;
        int i = 0;
        for (; i < left - 1; i++)
        {
            first = cur;
            cur = cur->next;
        }
        ListNode *last = cur;
        ListNode *pre = nullptr;
        for (; i < right; i++)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        last->next = cur;
        if (!first) return pre;
        first->next = pre;
        return head;
    }
};