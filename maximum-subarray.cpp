#include "helper.cpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        vector <int> res;
        int cur = nums[0];
        int mxx = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            cur = max(cur, 0) + nums[i];
            mxx = max(cur, mxx);
        }
        return mxx;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    vector <int> nums = {-1,3};
    int res = solution.maxSubArray(nums);
    cout << res << endl;
    return 0;
}