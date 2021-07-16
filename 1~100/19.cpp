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
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *first = head;
		ListNode *second = first;
		ListNode *bef = first;
		if (first->next == nullptr) return {};
		int cnt = 1;
		while (first->next != nullptr)
		{
			cnt++;
			bef = first;
			first = first->next;
		}
		if (n == 1)
		{
			bef->next = nullptr;
			delete first;
			return head;
		}
		first = head;
		bef = first;
		if (n == cnt)
		{
			head = first->next;
			delete first;
			return head;
		}
		for (int i = 0; i < n - 1; i++)
			second = second->next;
		while (second->next != nullptr)
		{
			bef = first;
			first = first->next;
			second = second->next;
		}
		bef->next = first->next;
		first->next = nullptr;
		delete first;
		return head;
	}
};