class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        try {
            auto bef = 0, add = 0;
            ListNode *head = l1, *cur = l1;
            while (l1 != NULL) {
                if (l2 == NULL) // empty l2
                    bef = l1->val + add;
                else {
                    bef = l1->val + l2->val + add;
                    l2 = l2->next;
                }
                l1 = l1->next;
                add = bef / 10;
                bef %= 10;
                cur->val = bef;
                if (l1 == NULL) // no next
                    break;
                cur = cur->next;
            }
            if (l2 != NULL) { // longer l2
                cur->next = l2;
                cur = cur->next;
            }
            while (l2 != NULL) {
                bef = l2->val + add;
                add = bef / 10;
                bef %= 10;
                l2 = l2->next;
                cur->val = bef;
                if (l2 == NULL)
                    break;
                cur = cur->next;
            }
            if (add == 1) { // add at end
                auto *t = new ListNode(1);
                cur->next = t;
            } else if (cur != NULL) // end not empty
                cur->next = NULL;
            return head;
        }
        catch (const exception &exc) {
            // catch anything thrown within try block that derives from std::exception
            cerr << exc.what();
        }
    }
};