#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;


inline bool in_map(map <char, int> &m, char key)
{
    return (key != '.' && m.find(key) != m.end());
}

bool    valid_row(vector<vector<char>>& board, map<char ,int> &hash, int row)
{
    char c;
    for (int i = 0; i < 9; i++)
    {
        c = board[row][i];
        if (c != '.' && in_map(hash, c))
            return false;
        hash[c] = 1;
    }
    return true;
}


bool    valid_col(vector<vector<char>>& board, map<char ,int> &hash, int col)
{
    char c;
    for (int i = 0; i < 9; i++)
    {
        c = board[i][col];
        if (c != '.' && in_map(hash, c))
            return false;
        hash[c] = 1;
    }
    return true;
}

bool    valid_nin(vector<vector<char>>& board, map<char ,int> &hash, int count)
{
    char c;
    int idx;
    int row;
    int col;
    col = (count % 3) * 3;
    row = (count / 3) * 3;
    idx = (row / 3) * 3 + (col / 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c = board[row + i][col + j];
            if (c != '.' && in_map(hash, c))
                return false;
            hash[c] = 1;
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int val;
        int count = 0;
        map <char, int> r_hash;
        map <char, int> c_hash;
        map <char, int> s_hash;
        for (int i = 0; i < 9; i += 1)
        {
            if (!valid_row(board, r_hash, i))
                return false;
            if (!valid_col(board, c_hash, i))
                return false;
            if (!valid_nin(board, s_hash, i))
                return false;
            r_hash.erase(r_hash.begin(), r_hash.end());
            c_hash.erase(c_hash.begin(), c_hash.end());
            s_hash.erase(s_hash.begin(), s_hash.end());
        }
     return true;
    }
};


int main() {
    // Create test cases
    Solution solution;
    vector<vector<char>> board1 = {
    {'1','2','.','.','3','.','.','.','.'},
    {'4','.','.','5','.','.','.','.','.'},
    {'.','9','8','.','.','.','.','.','3'},
    {'5','.','.','.','6','.','.','.','4'},
    {'.','.','.','8','.','3','.','.','5'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','.','.','.','.','.','2','.','.'},
    {'.','.','.','4','1','9','.','.','8'},
    {'.','.','.','.','8','.','.','7','9'}
    };
    // Test case 1
    bool result1 = solution.isValidSudoku(board1);
    cout << "Test Case 1:" << endl;
    printResult(result1);
    // vector<vector<char>> board2 = {
    //     {'.','.','.','.','5','.','.','1','.'},
    //     {'.','4','.','3','.','.','.','.','.'},
    //     {'.','.','.','.','.','3','.','.','1'},
    //     {'8','.','.','.','.','.','.','2','.'},
    //     {'.','.','2','.','7','.','.','.','.'},
    //     {'.','1','5','.','.','.','.','.','.'},
    //     {'.','.','.','.','.','2','.','.','.'},
    //     {'.','2','.','9','.','.','.','.','.'},
    //     {'.','.','4','.','.','.','.','.','.'}
    //     };
    // vector<vector<char>> board3 = {
    //      {'.','.','4','.','.','.','6','3','.'},
    //      {'.','.','.','.','.','.','.','.','.'},
    //      {'5','.','.','.','.','.','.','9','.'},
    //      {'.','.','.','5','6','.','.','.','.'},
    //      {'4','.','3','.','.','.','.','.','1'},
    //      {'.','.','.','7','.','.','.','.','.'},
    //      {'.','.','.','5','.','.','.','.','.'},
    //      {'.','.','.','.','.','.','.','.','.'},
    //      {'.','.','.','.','.','.','.','.','.'}
    // };
    // bool result2 = solution.isValidSudoku(board2);
    // cout << "Test Case 2:" << endl;
    // printResult(result2);
    
    // bool result3 = solution.isValidSudoku(board3);
    // cout << "Test Case 3:" << endl;
    // printResult(result3);


    vector<vector<char>> board4 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','2','.','.','.','.','6','.'},
        {'2','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','1','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool result4 = solution.isValidSudoku(board4);
    cout << "Test Case 4:" << endl;
    printResult(result4);


    return 0;
}


//          [[".",".","4",".",".",".","6","3","."]
//          ,[".",".",".",".",".",".",".",".","."]
//          ,["5",".",".",".",".",".",".","9","."]
//          ,[".",".",".","5","6",".",".",".","."]
//          ,["4",".","3",".",".",".",".",".","1"]
//          ,[".",".",".","7",".",".",".",".","."]
//          ,[".",".",".","5",".",".",".",".","."]
//          ,[".",".",".",".",".",".",".",".","."]
//          ,[".",".",".",".",".",".",".",".","."]]