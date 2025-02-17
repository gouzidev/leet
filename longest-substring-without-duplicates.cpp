#include "helper.cpp"

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest = 0;
        int count = 0;
        map <char, int> hash;
        int i = 0;
        while (i < s.size())
        {
            if (hash.find(s[i]) != hash.end())
            {
                i = hash.find(s[i])->second + 1;
                hash.clear();
                count = 0;
            }
            else
            {
                hash.insert({s[i], i});
                count++;
                i++;
            }
            if (count > longest)
                longest = count;
        }
        return longest;   
    }
};

int main() {
    // Create test cases
    Solution solution;
    cout << "res- > " << solution.lengthOfLongestSubstring(" ") << endl;
    return 0;
}
