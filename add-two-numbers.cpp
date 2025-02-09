#include "helper.cpp"



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
        ListNode    *l2_head = NULL;
        ListNode    *res_head = NULL;
        ListNode    *last = NULL;
        unsigned long long power(unsigned long long n, unsigned p)
        {
            unsigned long long r = 1;
            while (p--)
            {
                r = r * n;
            }
            return r;
        }
        void add_back(ListNode **head, ListNode **last, ListNode *node)
        {
            if ((*head) == NULL)
                *head = node;
            else
                (*last)->next = node;
            *last = node;
        }
        long long sumList(ListNode   *head)
        {
            long long sum = 0;
            long long n = 0;
            while (head)
            {
                sum += head->val * power(10, n++);
                head = head->next;
            }
            return sum;
        }
        void printList(ListNode *head)
        {
            while (head)
            {
                cout << head->val << " -> ";
                head = head->next;
            }
            cout << endl;
        }
        
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            int rem = 0;
            int res = 0;
            ListNode *res_head = NULL;
            ListNode *last = NULL;
            while (l1 && l2)
            {
                res = l1->val + l2->val + rem;
                rem = res / 10;
                ListNode    *newNode = new ListNode(res % 10);
                add_back(&res_head, &last, newNode);
                l1 = l1->next;
                l2 = l2->next;
            }
            while (l1)
            {
                res = l1->val + rem;
                ListNode    *newNode = new ListNode(res % 10);
                rem = res / 10;
                add_back(&res_head, &last, newNode);
                l1 = l1->next;
            }
            while (l2)
            {
                res = l2->val + rem;
                ListNode    *newNode = new ListNode(res % 10);
                rem = res / 10;
                add_back(&res_head, &last, newNode);
                l2 = l2->next;
            }
            if (rem)
            {
                ListNode    *newNode = new ListNode(rem);
                add_back(&res_head, &last, newNode); 
            }
            return res_head;
        }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases // 0, 1, 2, 3, 4, 5  [1,9,9,9,9,9,9,9,9,9]


    Solution solution;
    ListNode *h1 = new ListNode(2);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(1);
    h1->next->next->next->next = new ListNode(2);

    ListNode *h2 = new ListNode(5);
    h2->next = new ListNode(6);
    h2->next->next = new ListNode(4);
    h2->next->next->next = new ListNode(9);
    ListNode *res = solution.addTwoNumbers(h1, h2);
    solution.printList(res);
    return 0;
}
