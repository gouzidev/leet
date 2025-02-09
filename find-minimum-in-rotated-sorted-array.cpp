#include "helper.cpp"

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int m;
        int s = 0;   
        int e = nums.size();   
        int small = nums[0];
        if (nums.size() == 1)
            return nums[0];
        while (s < e)
        {
            m = ((e - s) / 2) + s;
            if (nums[e - 1] < nums[m])
                s = m;
            else if (nums[m] == small)
                return small;
            else
                e = m;
            if (nums[m] < small)
                small = nums[m];
        }
        return small;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    vector <int> nums = {3,1,2};
    cout << solution.findMin(nums) << endl;
    return 0;
}
