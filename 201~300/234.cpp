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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr) return true;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *right = reverseList(slow->next);
        ListNode *p1 = head;
        ListNode *p2 = right;
        bool ret = true;
        while (p2 != nullptr)
        {
            if (p1->val != p2->val)
            {
                ret = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        slow->next = reverseList(right);
        return ret;
    }
};