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


inline char lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}
class Solution {
public:
    bool isPalindrome(string s)
    {
        int end;
        int start;
        int even;

        if (s.size() < 2)
            return true;

        even = (s.size() % 2 == 0);
        end = s.size() - 1;
        start = 0;
        while (end > start)
        {
            if (even)
            {
                if (!isalnum(s[end]) && !isalnum(s[start]))
                {
                    end--;
                    start++;
                }
                else if (s[end] != s[start])
                    return false;
                end--;
                start++;
            }
            else
            {
                while (end > start && !isalnum(s[end]))
                    end--;
                while (start < end && !isalnum(s[start]))
                    start++;
                if (s[start] != s[end])
                    return false;
                end--;
                start++;
            }
        }
        return true;
    }
};


int main() {
    // Create test cases
    Solution solution;
    
    string str = "Was it a car or a cat I saw?";
    bool result1 = solution.isPalindrome(str);
    cout << "Test Case 1: ->  " << (result1 ? "true" : "not true") << endl;
    
    bool result2 = solution.isPalindrome("'a.'");
    cout << "Test Case 2: ->  " << (result2 ? "true" : "not true") << endl;
    
    bool result3 = solution.isPalindrome("tab a cat");
    cout << "Test Case 3: ->  " << (result3 ? "true" : "not true") << endl;
    
    return 0;
}
