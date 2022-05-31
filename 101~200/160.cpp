/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *pa = headA, *pb = headB;
        if (!pa || !pb) return nullptr;
        while (pa != pb)
        {
            pa = (!pa ? headB : pa->next);
            pb = (!pb ? headA : pb->next);
        }
        return pa;
    }
};