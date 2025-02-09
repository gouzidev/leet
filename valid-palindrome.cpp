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

char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

class Solution {
public:
    bool isPalindrome(string s)
    {
        char c;
        int b = 0;
        int e = s.size() - 1;
        if (s.size() < 2)
            return true;
        while (b < e)
        {
            if (isalnum(s[e]) && isalnum(s[b]))
            {
                if (lower(s[e]) == lower(s[b]))
                {
                    b++;
                    e--;
                }
                else
                    return (false);
            }
            if (!isalnum(s[e]))
                e--;
            if (!isalnum(s[b]))
                b++;
        }
        return true;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    // Test case 1
    bool result1 = solution.isPalindrome("A man, a plan, a canal: Panama");
    cout << "Test Case 1:" << endl;
    printResult(result1);
    
    // Test case 2
    bool result2 = solution.isPalindrome(" ");
    cout << "Test Case 2:" << endl;
    printResult(result2);
    
    return 0;
}
