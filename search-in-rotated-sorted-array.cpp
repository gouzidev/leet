#include "helper.cpp"

class Solution {
    int i  = 0;
public:
    
    int search(vector<int>& nums, int target)
    {
        int m;
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e)
        {
            m = ((e - s) / 2) + s;
            // cout << "n -> " << nums[m] << "  m -> " << m << "  s -> " << s << "  e -> " << e << endl;
            if (nums[m] == target)
                return m;
            if (nums[m] >= nums[s])
            {
                if (target >= nums[s] && target <= nums[m])
                    e = m - 1;
                else
                    s = m + 1;
            }
            else 
            {
                if (target <= nums[e] && target >= nums[m])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return -1;
    }
};

int main(int ac, char **av) {
    // Create test cases
    Solution solution;
    vector <int> nums = {4,5,6,7,0,1,2};
    cout << solution.search(nums, atoi(av[1])) << endl;
    return 0;
}
