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
// 找中点+反转后半部分+合并前后两部分
class Solution
{
public:
    void printList(ListNode *head)
    {
        ListNode *first = head;
        while (first != nullptr)
        {
            cout << first->val << ' ';
            first = first->next;
        }
        cout << endl;
    }
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *last = head;
        ListNode *middle = head;
        while (last != nullptr)
        {
            last = last->next;
            if (last == nullptr)
                break;
            middle = middle->next;
            last = last->next;
        }
        return middle;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *middle = head;
        ListNode *cur = middle;
        ListNode *next = middle->next;
        while (next != nullptr)
        {
            cur->next = next->next;
            next->next = middle;
            middle = next;
            next = cur->next;
        }
        return middle;
    }
    void mergeList(ListNode *left, ListNode *right)
    {
        while (left->next != nullptr && right->next != nullptr)
        {
            ListNode *ln = left->next;
            ListNode *rn = right->next;
            left->next = right;
            left = ln;
            right->next = left;
            right = rn;
        }
    }
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;
        ListNode *middle = findMiddle(head);
        // printList(middle);
        ListNode *new_mid = reverseList(middle);
        // printList(new_mid);
        mergeList(head, new_mid);
    }
};
