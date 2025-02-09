#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

void print_vec(vector <int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
    cout << endl;
}

void print_vec_pair(vector <pair <int, int>> v)
{
    cout << "______________" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << "  -> ";
        cout << v[i].second << "  ";
        cout << endl;
    }
    cout << "______________" << endl;
}

void print_map(map <int, int, greater <int>> m)
{
    cout << "______________" << endl;
    for (pair <int, int> p : m)
    {
        cout << p.first << " -> " << p.second << " | ";
    }
    cout << endl;
    cout << "______________" << endl;
}

class Solution {
public:
    inline int min_zero(int a, int b)
    {
        int c = a - b;
        if (c > 0)
            return c;
        return 0;
    }
    inline int get_water_trapped(vector<int> &h, int left, int right)
    {
        int trapped = 0;
        int i = left;
        int m;
        m = min(h[left], h[right]);
        while (i < right)
            trapped += min_zero(m, h[i++]);
        return trapped; 
    }
    inline int get_last_trapped(vector<int> &h, int left, int right) // eft is bigger
    {
        int trapped = 0;
        int i = right;
        int big = h[i];
        while (left < i)
        {
            if (h[i] >= big)
            {
                big = h[i];
            }
            if (h[i] < big)
                trapped += min_zero(big, h[i]);
            i--;
        }
        return trapped; 
    }
    int trap(vector<int>& h) {
        int water = 0;
        int left = 0;
        int top = -1;
        if (h.size() < 2)
            return 0;
        for (int i = 0; i < h.size(); i++)
        {
            if (h[i] >= top)
            {
                water += get_water_trapped(h, left, i);
                top = h[i];
                left = i;
            }
        }
        water += get_last_trapped(h, left, h.size() - 1);
        return water;
    }
};


void printResult(int result) {
    cout << "Result: " << (result) << endl;
}

int main() {
    // Create test cases
    Solution solution;
    // fix left pointer is biggest
    vector <int> heights = {4,2,0,3,2,5};
    // Test case 1
    int result1 = solution.trap(heights);
    cout << "Test Case 1:" << endl;
    printResult(result1);
   
    return 0;
}
