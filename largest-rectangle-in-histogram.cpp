#include <string>
#include <unordered_map>
#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

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
    int largestRectangleArea(vector<int>& h) {
        int i = -1;
        int tall_surf = 0;
        int temp_surf = 0;
        int popped;
        stack <int> st;
        while (++i < h.size())
        {
            while (!st.empty() && h[st.top()] >= h[i])
            {
                popped = st.top();
                st.pop();
                if (st.empty())
                {
                    temp_surf = h[popped] * (i);
                    if (temp_surf > tall_surf)
                        tall_surf = temp_surf;
                    break;
                }
                else
                    temp_surf = h[popped] * (i - st.top() - 1);
                if (temp_surf > tall_surf)
                    tall_surf = temp_surf;
            }
            st.push(i);
        }
        while (!st.empty())
        {
            popped = st.top();
            st.pop();
            if (st.empty())
                temp_surf = h[popped] * (i);
            else
                temp_surf = h[popped] * (i - st.top() - 1);
            if (temp_surf > tall_surf)
                tall_surf = temp_surf;
        }
        return tall_surf;
    }
};


int main() {
    // Create test cases
    Solution solution;
    vector <int> heights = {4,2};
    // vector <int> heights = {1};
    // vector <int> heights = {4,2,0,3,2,5};
    int histogram = solution.largestRectangleArea(heights);
    cout << histogram << endl;
    return 0;
}
