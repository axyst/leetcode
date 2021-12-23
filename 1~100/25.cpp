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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        ListNode *cur = dummy;
        dummy->next = head;
        int cnt = 0;
        while (cur->next)
        {
            cur = cur->next;
            cnt++;
        }
        while (cnt >= k)
        {
            cur = pre->next;
            for (int i = 0; i < k - 1; i++)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                tmp->next = pre->next;
                pre->next = tmp;
            }
            pre = cur;
            cnt -= k;
        }
        return dummy->next;
    }
};