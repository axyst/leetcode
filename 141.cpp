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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr) return false;
        if (head->next == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            else break;
            if (slow == fast) return true;
        }
        return false;
    }
};