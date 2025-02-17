#include "helper.cpp"

class Solution {
public:
    void remove_from_map(map <char, short> &m, char &c)
    {
        if (m.find(c) != m.end())
            m[c]--;
    }
    bool    equal_maps(map <char, short> &big_map, map <char, short> &small_map)
    {
        size_t l2 = small_map.size();
        size_t count = 0;
        for (pair <char, short> p : big_map)
        {
            if (small_map.find(p.first) != small_map.end()) 
            {
                if (small_map[p.first] == p.second)
                    count++;
            }
        }
        return (count == l2);
    }
    bool checkInclusion(string s1, string s2)
    {
        size_t l2 = s2.size();
        size_t l1 = s1.size();
        if (l1 > l2)
            return false;
        map <char, short> m2;
        map <char, short> m1;
        int i = 0;
        for (char &c : s1)
        {
            if (m1.find(c) != m1.end())
                m1[c]++;
            else
                m1[c] = 1;
        }
        for (int i = 0; i < s2.size(); i++)
        {
            char &c = s2[i];
            if (m2.find(c) != m2.end())
                m2[c]++;
            else
                m2[c] = 1;
            if (i >= l1)
                remove_from_map(m2, s2[i - l1]);
            if (equal_maps(m2, m1))
                return true;
        }
        cout << endl;
        return false;
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    
    // Test case 1
    bool res  = solution.checkInclusion("a", "lecabee");
    if (res)
        cout << "s1 : " << "'lecabee'" << "  includes : " << "'abc'" << endl;
    else
        cout << "NOT " << endl;
    return 0;
}
