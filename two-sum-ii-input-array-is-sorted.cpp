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

class Solution1 {
public:
    int binary_search(vector <int> &nums, int start_idx, int end_idx, int num)
    //                                          2,        4,        5
    {
        int mid;
        int right;
        int left;
        int size = end_idx - start_idx; // 2
        if (size == 1)
        {
            if (nums[start_idx] == num) 
                return start_idx;
            else return -1;
        }
        // mid = nums[2] -> 5
        mid = nums[start_idx + size / 2]; // size = 4   1, 3, 5, 7  // 2 / 2 -> 1
        if (num < mid) // 5 < 5  -> false
        {
            return binary_search(nums, start_idx, start_idx + (size / 2), num); // 0 -> 2  
        }
        else //                        2, 4
            return binary_search(nums, start_idx + size / 2, end_idx, num); // 2 -> 4
    }
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i;
        int j;
        int search;
        int idx_search;
        vector <int> res = {-1, -1};
        i = 0;
        j = 1;
        for (int i = 0; i < numbers.size(); i++)
        {
            search = target - numbers[i];
            if (i != 0 && numbers[i] == numbers[i - 1] && i + 1 < numbers.size() && numbers[i + 1] == numbers[i] )
                continue;
            idx_search = binary_search(numbers, 0, numbers.size(), search);
            if (idx_search != -1 && i != idx_search)
            {
                res[0] = idx_search + 1;
                res[1] = i + 1;
                sort(res.begin(), res.end());
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i;
        int j;
        vector <int> res = {-1, -1};
        i = 0;
        j = numbers.size() - 1;
        while ( i < j )
        {
            if (numbers[i] + numbers[j] < target)
                i++;
            else if (numbers[i] + numbers[j] > target)
                j--;
            else
            {
                (res[0] = i + 1, res[1] = j + 1);
                return res;
            }
        }
        return res;
    }
};

void printResult(vector <int> result) {
    print_vec(result);
}

int main() {
    // Create test cases
    Solution solution;
    vector <int> nums = {-2, 0,1,2, 3, 6, 9};
    vector <int> res;
    res = solution.twoSum(nums, 5);
    printResult(res);
    return 0;
}
