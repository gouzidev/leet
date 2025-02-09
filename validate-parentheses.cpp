#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
#include<algorithm>
#include<stack>

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
    bool isValid(string s) {
        stack <char> st;
        if (s.size() % 2 != 0)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (s[i] == '}' && st.top() != '{')
                    return false;
                if (s[i] == ']' && st.top() != '[')
                    return false;
                if (s[i] == ')' && st.top() != '(')
                    return false;
                st.pop();
            }
        }
        return (st.empty());
    }
};


void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    // Test case 1

    // Test case 2
    bool result2 = solution.isValid("(");
    cout << "Test Case 2:" << endl;
    printResult(result2);
    
    return 0;
}
