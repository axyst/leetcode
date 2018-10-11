class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        try {
            auto bef = 0, add = 0;
            ListNode *head = l1, *cur = l1;
            while (l1 != nullptr) {
                if (l2 == nullptr)
                    bef = l1->val + add;
                else {
                    bef = l1->val + l2->val + add;
                    l2 = l2->next;
                }
                l1 = l1->next;
                add = bef / 10;
                bef %= 10;
                cur->val = bef;
                if (l1 == nullptr)
                    break;
                cur = cur->next;
            }
            if (l2 != nullptr) { // longer l2
                cur->next = l2;
                cur = cur->next;
            }
            while (l2 != nullptr) {
                bef = l2->val + add;
                add = bef / 10;
                bef %= 10;
                l2 = l2->next;
                cur->val = bef;
                if (l2 == nullptr)
                    break;
                cur = cur->next;
            }
            if (add == 1) { // add at end
                auto *t = new ListNode(1);
                cur->next = t;
            } else if (cur != nullptr) // end not empty
                cur->next = nullptr;
            return head;
        }
        catch (const exception &exc) {
            cerr << exc.what() << endl;
        }
    }
};