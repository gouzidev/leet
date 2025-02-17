#include "helper.cpp"

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int cur = nums[0];
        int mxx = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] * cur > mxx)
            {
                cur = cur * nums[i];
                mxx = max(cur , nums[i]);
                mxx = cur;
            }
            else if (cur * nums[i] == 0)
            {
                cur = nums[i];
                mxx = max(mxx , nums[i]);
            }
            else
            {
                cur = cur * nums[i];
                mxx = max(mxx , nums[i]);
            }
        }
        mxx = max(cur , mxx);
        return mxx;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;

     vector <int> nums = {2,-5,-2,-4,3};
    int res = solution.maxProduct(nums);
    cout << res << endl;
    
    return 0;
}
