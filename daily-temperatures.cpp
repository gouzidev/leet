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
    vector<int> dailyTemperatures(vector<int>& t) {
        int curr_temp;
        int days_count = 0;
        vector <int> res (t.size(), 0);
        stack <int> s;
        vector <int>::iterator end;
        int i = 0;
        s.push(i);
        while (i < t.size() - 1)
        {
            if (t[i] >= t[i + 1])
            {
                cout <<  "pushing: num(" << i << ")"  << "- > " << t[i] << endl;
                s.push(i + 1);
            }
            else
            {
                while (!s.empty() && t[i + 1] > t[s.top()])  // t[i + 1] => 40 (curr_temp)
                {
                    res[s.top()] = i - s.top() + 1;
                    s.pop();
                }
                s.push(i + 1);
            }
            i++;
        }
        return res;
    }
};

int main() {
    // Create test cases
    Solution solution;
    
    // Test case 1

    vector<int> temperatures = {30,40,50,60};
    vector<int>  result = solution.dailyTemperatures(temperatures);
    cout << "Test Case 1:" << endl;
    print_vec(result);

    // temperatures = {73,74,75,71,69,72,76,73};
    // result = solution.dailyTemperatures(temperatures);
    // cout << "Test Case 2:" << endl;
    // print_vec(result);
    
    // temperatures = {30,40,50,60};
    // result = solution.dailyTemperatures(temperatures);
    // cout << "Test Case 3:" << endl;
    // print_vec(result);


    // temperatures = {30,60,90};
    // result = solution.dailyTemperatures(temperatures);
    // cout << "Test Case 4:" << endl;
    // print_vec(result);

}
