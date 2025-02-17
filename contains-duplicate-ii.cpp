#include "helper.cpp"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        map <int, bool> hash;
        int i = 0;
        int j = 1;
        while (i < nums.size())
        {
            
        }
        return false;
    }
};

int main() {
    // Create test cases
    Solution solution;
    // Test case 1
    vector <int> nums = {3,1,2,3};
    bool result1 = solution.containsNearbyDuplicate(nums, 2);
    cout << "->  " << boolalpha << result1 << endl;
    return 0;
}
