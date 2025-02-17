#include "helper.cpp"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int cur1 = nums[0];
        int cur2 = nums[0];
        int totalsum = nums[0];
        int mxx = nums[0];
        int mnn = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            cur1 = max(cur1, 0) + nums[i];
            cur2 = min(nums[i], nums[i] + cur2);
            mxx = max(cur1, mxx);
            mnn = min(cur2, mnn);
            totalsum += nums[i];
        }
        cout << "max     -> " << mnn << endl;
        cout << "min     -> " << mxx << endl;
        cout << "totalsum -> " << mnn << endl;
        return max(totalsum - mnn, mxx);
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    vector <int> nums = {-3,-2,-3};
    int res = solution.maxSubarraySumCircular(nums);
    cout << res << endl;
    return 0;
}