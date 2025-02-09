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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode    *curr = NULL;
        ListNode    *h3 = curr;
        while (h1 && h2)
        {
            ListNode    *node = new ListNode();
            if (h1->val > h2->val)
                node->val = h2->val;
            else
                node->val = h1->val;
            if (h1->val > h2->val)
                h2 = h2->next;
            else
                h1 = h1->next;
            if (curr)
            {
                curr->next = node;
                curr = curr->next;
            }
            else
            {
                curr = node;
                h3 = curr;
            }
        }
        while (h1)
        {
            ListNode    *node = new ListNode(h1->val);
            if (curr)
            {
                curr->next = node;
                curr = curr->next;
            }
            else
            {
                curr = node;
                h3 = curr;
            }
            h1 = h1->next;
        }
        while (h2)
        {
            ListNode    *node = new ListNode(h2->val);
            if (curr)
            {
                curr->next = node;
                curr = curr->next;
            }
            else
            {
                curr = node;
                h3 = curr;
            }
            h2 = h2->next;
        }
        return h3;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    ListNode *h1 = new ListNode(7);
    h1->next = new ListNode(8);
    h1->next->next = new ListNode(9);
    ListNode *h2 = new ListNode(5);
    h2->next = new ListNode(6);
    h2->next->next = new ListNode(10);
    ListNode *res = solution.mergeTwoLists(h1, h2);
    // Test case 1
    solution.printList(res);
    
    
    return 0;
}
