class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        try {
            int num = 0;
            ListNode *test = head;
            while (test != NULL) {
                num++;
                test = test->next;
            }
            ListNode *ret = new ListNode(0);
            ListNode *rh = ret;
            int cnt = 1;
            while (head != NULL) {
                if (cnt != num - n + 1) {
                    ListNode *cur = new ListNode(head->val);
                    ret->next = cur;
                    ret = cur;
                }
                cnt++;
                head = head->next;
            }
            return rh->next;
        }
        catch (const exception &exc) {
            cout << exc.what() << endl;
        }
    };
};