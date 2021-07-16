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
	ListNode *swapPairs(ListNode *head)
	{
		ListNode *first = head;
		if (first == nullptr || first->next == nullptr)
			return head;
		ListNode *second = first->next;
		head = second;
		ListNode *bef = nullptr;
		ListNode *nxt = second->next;
		while (second != nullptr && second->next != nullptr)
		{
			nxt = second->next;
			if (bef != nullptr) bef->next = second;
			second->next = first;
			bef = first;
			first->next = nxt;
			first = nxt;
			second = first->next;
		}
		if (second != nullptr)
		{
			if (bef != nullptr) bef->next = second;
			second->next = first;
			first->next = nullptr;
		}
		return head;
	}
};