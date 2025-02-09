#include <string>
#include <unordered_map>
#include <map>
#include <set>
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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) // nums = [-1,0,1,2,-1,-4]
    {
        
        vector <vector <int> > res;
        int curr_target;
        set <vector <int>> hash;
        vector <int>  temp ;
        int i = 0;
        int k;
        int j;
        int l = nums.size();
        sort(nums.begin(), nums.end());
        while (i < l)
        {
            curr_target = -nums[i];
            k = i + 1;
            j = l - 1;
            while (k < j)
            {
                if (nums[k] + nums[j] > curr_target)
                    j--;
                else if (nums[k] + nums[j] < curr_target)
                    k++;
              
                else if (nums[k] + nums[j] == curr_target)
                {
                    temp.erase(temp.begin(), temp.end());
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    sort(temp.begin(), temp.end());
                    if (hash.find(temp) == hash.end())
                    {
                        hash.insert(temp);
                        res.push_back(temp);
                    }
                    else
                        i++;
                }
            }
            i++;
        }
        return res;
    };
};

void printResult(vector<vector<int>> result) {
    for (auto v : result)
    {
        print_vec(v);
    }
    cout << endl;
}

int main() {
    // Create test cases
    Solution solution;
    vector <int> nums = {0,0,0,0};
    vector <vector <int>> res = solution.threeSum(nums); // 1, 4
    printResult(res);

    nums = {1,-1,-1,0};
    res = solution.threeSum(nums); // 1, 4
    printResult(res);

    nums = {-4, -3, -2, -1, -1, 0, 0, 1, 2, 3, 4};
    res = solution.threeSum(nums); // 1, 4
    printResult(res);

    nums = {-2,0,1,1,2};
    res = solution.threeSum(nums); // 1, 4
    printResult(res);
    return 0;
}
