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
    bool hasCycle(ListNode* head)
    {
        ListNode    *slow;
        ListNode    *fast;

        slow = head;
        fast = head;
        if (fast)
            fast = fast->next;
        while (slow && fast)
        {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        return false;
    }
    void printList(ListNode *head)
    {
        while (head)
        {
            cout << head->val << "  ";
            head = head->next;
        }
        cout << endl;
    }
};


void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    ListNode *h1 = new ListNode(7);
    h1->next = h1;

    // Test case 1
    cout << boolalpha << solution.hasCycle(h1) << endl;
    return 0;
}
