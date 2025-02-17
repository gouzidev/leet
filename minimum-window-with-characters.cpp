#include "helper.cpp"

class Solution {
public:
    string minWindow(string s, string t)
    {
        int l = 0;
        int r = 0;
        map <char, int> m;
        for (char &c : t)
        {
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m[c]++;
        }
        while (s[r])
        {
            
        }
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    
    return 0;
}
