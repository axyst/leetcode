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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int add = 0;
        ListNode head(0), *cur = &head;
        while (l1 != nullptr || l2 != nullptr || add)
        {
            int bef = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + add;
            cur->next = new ListNode(bef % 10);
            add = bef / 10;
            l1 != nullptr ? l1 = l1->next : l1;
            l2 != nullptr ? l2 = l2->next : l2;
            cur = cur->next;
        }
        return head.next;
    }
};