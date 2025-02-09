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

    ListNode    *head;
    int         count;
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode    *last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    int countList(ListNode  *curr)
    {
        int i = 0;
        while (curr && ++i)
            curr = curr->next;
        return i;
    }
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
    void reorderList(ListNode* head)
    {
        if (!head || !head->next)
            return;
        ListNode    *slow;
        ListNode    *prev;
        ListNode    *fast;
        prev = NULL;
        slow = head;
        fast = head->next;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = slow;
        slow = slow->next;
        slow = reverseList(slow);
        prev->next = NULL;
        ListNode *next_head;
        ListNode *next_slow;
        while (head && slow)
        {
            next_slow = slow->next;
            next_head = head->next;
            head->next = slow;
            slow->next = next_head;
            head = next_head;
            slow = next_slow;
        }
    }
    void printList(ListNode *head)
    {
        if (hasCycle(head))
            cout << "has cycle !"; 
        else
        {
            while (head)
            {
                cout << head->val << "  ";
                head = head->next;
            }
        }
        cout << endl;
    }
};



int main() {
    // Create test cases // 0, 1, 2, 3, 4, 5
    Solution solution;
    ListNode *h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4);
    h1->next->next->next->next = new ListNode(6);
    solution.reorderList(h1);
    solution.printList(h1);
    return 0;
}
