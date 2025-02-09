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
    void add_back(ListNode **head, ListNode **last, ListNode *node)
    {
        if ((*head) == NULL)
            *head = node;
        else
            (*last)->next = node;
        *last = node;
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
    int findDuplicate(vector<int>& nums)
    {
        int i = 0;
        int j = 1;
        size_t size = nums.size();
        while (true)
        {
            if (nums[i] == nums[j])
                return nums[i];
            i = (i + 1) % size;
            j = (j + 2) % size;
            if (j == i)
                j = (j + 1) % size;
        }
        return -1;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    vector <int> nums = {2,1,2};
    cout << solution.findDuplicate(nums);
    // Test case 1
    
    return 0;
}
