#include "helper.cpp"


class Solution {
    private:
    bool searchVector(vector <int> &vec, int &size, int &target)
    {
        int start = 0;
        int end = size;
        int m;
        while (true)
        {
            m = ((end - start) / 2) + start;
            if (vec[m] == target)
                return true;
            else if (m == end || m == start)
                return false;
            else if (vec[m] > target)
                end = m;
            else if (vec[m] < target)
                start = m;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n_mx = matrix.size();
        int start_n = 0;
        int end_n = n_mx;
        int m_n;
        int n;
        n = matrix[0].size();
        while (true)
        {
            m_n = ((end_n - start_n) / 2) + start_n;
            if (matrix[m_n][0] <= target && matrix[m_n][n - 1] >= target)
                return searchVector(matrix[m_n], n, target);
            else if (m_n == start_n || m_n == end_n)
                return false;
            if (matrix[m_n][n - 1] < target)
                start_n = m_n;
            else if (matrix[m_n][0] > target)
                end_n = m_n;
            else
            {
                return false;
            }
        }
    }
};

void printResult(bool result) {
    cout << "Result: " << (result ? "true" : "false") << endl;
}

int main() {
    // Create test cases
    Solution solution;
    // vector <vector <int>> nums = {{1}};
    // vector <vector <int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector <vector <int>> nums = {{1, 3}};
    bool res = solution.searchMatrix(nums, 3);
    cout << boolalpha << res << endl;
    return 0;
}
