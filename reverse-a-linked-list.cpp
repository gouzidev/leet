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
    
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode    *last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};

class Solution2 {
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev;
        ListNode *next;
        prev = NULL;
        if (!head || !head->next)
            return head;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

int main() {
    // Create test cases
    Solution solution;
    ListNode *reversed;
    ListNode *n1 = new ListNode(4);
    ListNode *n2 = new ListNode(3);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    reversed = solution.reverseList(n1);
    solution.printList(reversed);
    // Test case 1
    // bool result1 = solution.solve();
    // cout << "Test Case 1:" << endl;
    // printResult(result1);
    return 0;
}
