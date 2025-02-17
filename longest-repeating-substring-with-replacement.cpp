#include "helper.cpp"

class Solution {
public:
    int max_vec(vector <int> v)
    {
        int m = 0;
        for (int i  = 0; i < v.size(); i++)
        {
            if (v[i] > m)
                m = v[i];
        }
        return m;
    }
    void print_window(string s, int l, int r)
    {
        while (l <= r)
        {
            cout << s[l] << " ";
            l++; 
        }
        cout << endl;
    }
    int characterReplacement(string s, int k)
    {
        int l = 0;
        int i = 0;
        int r = 1;
        int res = 0;
        int rem;
        int m = 0;
        int win_len;
        vector <int> chars (26, 0);
        chars[s[l] - 'A']++;
        chars[s[r] - 'A']++;
        while (s[r] && i++ < 10)
        {
            win_len = r - l + 1;
            m = max_vec(chars);
            rem = win_len - m;
            if (rem > k)
            {
                chars[s[l] - 'A']--;
                l++;
            }
            else
            {
                r++;
                res = max(win_len, res);
                if (r == s.size())
                    chars[s[r - 1] - 'A']++;
                else
                    chars[s[r] - 'A']++;
            }
        }
        res = max(win_len, res);
        return res;
    }
};

int main() {
    Solution solution;
    int res = solution.characterReplacement("ABAB", 2);

    cout << endl <<  "-> " << res << endl;
    return 0;
}
