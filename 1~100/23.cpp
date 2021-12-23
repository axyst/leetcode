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
    struct Status
    {
        int val;
        ListNode *ptr;
        Status(int x, ListNode *next) : val(x), ptr(next) {}
        bool operator<(const Status &rhs) const
        {
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int cnt = 0;
        for (ListNode *node : lists)
            if (node != nullptr)
                q.push(Status(node->val, node));
        ListNode head;
        ListNode *cur = &head;
        while (!q.empty())
        {
            ListNode *nd = q.top().ptr;
            cur->next = nd;
            cur = cur->next;
            q.pop();
            if (cur->next != nullptr)
                q.push(Status(cur->next->val, cur->next));
        }
        return head.next;
    }
};
