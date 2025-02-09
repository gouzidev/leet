#include "helper.cpp"

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int end = nums.size();
        int start = 0;
        int m;
        while (true)
        {
            m = ((end - start) / 2) + start;
            if (nums[m] == target)
                return m;
            else if (m == start || m == end)
                return -1;
            else if (nums[m] > target)
                end = m;
            else
                start = m;
            
        }
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    vector <int> nums = {-1,0,3,5,9,12};
    int idx = solution.search(nums, 9);
    cout << idx << endl;
    return 0;
}
