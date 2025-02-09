#include <string>
#include <unordered_map>
#include <map>
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

int zero_or_more(int a, int b)
{
    if (a - b < 0)
        return 0;
    return a - b;
}

class Solution {
public:
    int trap(vector<int>& height) {
        int left = height[0];
        int water = 0;
        int trapped = 0;
        int left_i = 0;
        int i = 0;
        while (i < height.size())
        {
            water += zero_or_more(left, height[i]);
            if (height[i] > left)
            {
                left_i = i;
                left = height[i];
                trapped += water;
                water = 0;
            }
            i++;
        }
        if (water)
        {
            
        }
        return water;
    }
};


int main() {
    // Create test cases
    Solution solution;
    
    vector <int> nums = {1,0,4,0,3};
    int res = solution.trap(nums);
    cout << "res -> " << res << endl;
    return 0;
}
