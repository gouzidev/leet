#include "helper.cpp"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        void printList(ListNode *head)
        {
            while (head)
            {
                cout << head->val << "  ";
                head = head->next;
            }
            cout << endl;
        }
        int removeRec(ListNode *prev, int n)
        {
            if (prev->next)
                n = removeRec(prev->next, n);
            cout << "n -> " << n << "  prev->val -> " << prev->val << endl;
            if (n == 0)
            {
                prev->next = prev->next->next;
            }
            return --n;
            
        }
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            n = removeRec(head, n);
            if (n == 0)
                head = head->next;
            return head;
        }
};


void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases // 0, 1, 2, 3, 4, 5
    Solution solution;
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1 = solution.removeNthFromEnd(h1, 2);
    solution.printList(h1);
    return 0;
}
