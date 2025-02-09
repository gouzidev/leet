#include "helper.cpp"

class Solution {
public:
    int get_hours(vector<int>& piles, int k)
    {
        int h = 0;
        for (int pile : piles)
        {
            // c < a + b
            // INTMAX < h + (pile / k)
            
            // a > c - b
            if (__INT_MAX__ - (pile / k) < h)
                return -1;
            h += (pile / k);
            if (pile % k)
                h += 1;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int max_m = *max_element(piles.begin(), piles.end());   
        int s = 0;
        int hours;
        int res = __INT_MAX__;
        int e = max_m + 1;
        int m;
        while (s <= e)
        {
            m = ((e - s) / 2) + s;
            hours = get_hours(piles, m);
            if (hours > h)
                s = m;
            else
                e = m;
            if (res > m && hours <= h && hours != -1)
                res = m;
            if (e - s < 2)
                break;
        }
        return res;
    }
};


int main() {
    // Create test cases
    Solution solution;
    vector <int> nums = {805306368,805306368,805306368};
    int idx = solution.minEatingSpeed(nums, 1000000000);
    cout << idx << endl;
    return 0;
}
