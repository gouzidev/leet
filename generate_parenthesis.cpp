#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

template  <typename T>
void print_vec(T v)
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
    void generate_paren(vector<string> &res, string s, int &n, int open, int clos)
    {
        cout << "s -> " << s << " |  n -> " << n  << " |  clos -> " << clos << endl;
        
        if (s.size() == (n * 2))
        {
            if (open == 0)
                res.push_back(s);
            return ;
        }

        if (clos < n && open)
            generate_paren(res, s + ")", n, open - 1, clos + 1);
        if (open < n)
            generate_paren(res, s + "(", n, open + 1, clos - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector <string> parenths;
        string res;
        int open = 1;
        int clos = 0;
        generate_paren(parenths,"(", n, open, clos);
        return parenths;
    }
};

int main() {
    // Create test cases
    Solution solution;
    vector <string> res = solution.generateParenthesis(2);
    print_vec(res);
    return 0;
}
