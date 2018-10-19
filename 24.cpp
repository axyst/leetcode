class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        try {
            ListNode *cur = new ListNode(0);
            ListNode *ret = cur;
            while (head != NULL) {
                ListNode *tmp = new ListNode(head->val);
                if (head->next != NULL) {
                    ListNode *tmp2 = new ListNode(head->next->val);
                    cur->next = tmp2;
                    cur->next->next = tmp;
                    head = head->next;
                } else {
                    cur->next = tmp;
                }
                cur = tmp;
                head = head->next;

            }
            return ret->next;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    };
};