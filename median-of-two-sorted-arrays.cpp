#include "helper.cpp"
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2)
    {
        if (arr1.empty())
        {
            if (arr2.size() % 2)
                return (arr2[arr2.size() / 2]);
            else
            {
                double el1 = arr2[arr2.size() / 2];
                double el2 = arr2[(arr2.size() / 2) - 1];
                double el = (el1 + el2) / 2;
                return el;
            }
        }
        if (arr2.empty())
        {
            if (arr1.size() % 2)
                return (arr1[arr1.size() / 2]);
            else
            {
                double el1 = arr1[arr1.size() / 2];
                double el2 = arr1[(arr1.size() / 2) - 1];
                double el = (el1 + el2) / 2;
                return el;
            }
        }
        

        size_t sizet = arr1.size() + arr2.size();
        vector <int> *p1 = &arr1;
        vector <int> *p2 = &arr2;

        if (arr1.size() > arr2.size())
        {
            p1 = &arr2;
            p2 = &arr1;
        }
        vector <int> &nums1 = *p1;
        vector <int> &nums2 = *p2;

        size_t size1 = nums1.size();
        size_t size2 = nums2.size();
        size_t l = 0; // of smaller
        size_t h = size1;
        double med = arr1[0];
        while (l <= h)
        {
            size_t m1 = (l + h) / 2; // (0 + 2) / 2 => 1;
            size_t m2 = ((sizet + 1) / 2) - m1; // 2
            if (m1 > 0 && m2 < size2 && nums1[m1 - 1] > nums2[m2])
                h = m1 - 1;
            else if (m2 > 0 &&  m1 < size1 && nums1[m1] < nums2[m2 - 1])
                l = m1 + 1;
            else
            {
                return get_median(nums1, nums2, m1, m2);
            }
        }
        return med;
    }
    double get_median(vector <int> &nums1, vector <int> &nums2, int m1, int m2)
    {
        size_t sizet = nums1.size() + nums2.size();
        double a; // nums1[m1]
        double b; // nums1[m1 - 1]
        double c; // nums2[m2]
        double d; // nums2[m2 - 1]
        if (m1 == 0)
            b = -INFINITY;
        else
            b = nums1[m1 - 1];
        if (m1 == nums1.size())
            a = INFINITY;
        else
            a = nums1[m1];

        if (m2 == 0)
            d = -INFINITY;
        else
            d = nums2[m2 - 1];

        if (m2 == nums2.size())
            c = INFINITY;
        else
            c = nums2[m2];
        if (sizet % 2) // ODD
            return max(b, d);
        double res = max(b, d) + min(a, c);
        return (res / 2.f);
    }
};


int main() {
    // Create test cases
    Solution solution;
    vector <int> nums1 = {3};
    vector <int> nums2 = {-2,-1};
    double med = solution.findMedianSortedArrays(nums1, nums2);
    cout << "median -> " << med << endl;
    
    return 0;
}
