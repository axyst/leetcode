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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *pre;
        pre->next = head;
        ListNode *cur = pre;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == (cur->next->next)->val)
            {
                int chk_val = cur->next->val;
                ListNode *checker = cur->next;
                while (checker && checker->val == chk_val)
                {
                    ListNode *tmp = checker;
                    checker = checker->next;
                    delete tmp;
                }
                cur->next = checker;
            }
            else cur = cur->next;
        }
        return pre->next;
    }
};