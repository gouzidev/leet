#include <string>
#include <unordered_map>
#include <set>
#include <stack>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

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

void print_int_bool_map(map <int, bool> m)
{
    cout << "______________" << endl;
    for (pair <int, bool> p : m)
    {
        cout << p.first << " -> " << boolalpha << p.second << " | ";
    }
    cout << endl;
    cout << "______________" << endl;
}

void print_char_int_map(map <char, int> m)
{
    cout << "______________" << endl;
    for (pair <char, int> p : m)
    {
        cout << p.first << " -> "  << p.second << " | ";
    }
    cout << endl;
    cout << "______________" << endl;
}

void print_int_int_map(map <int, int> m)
{
    cout << "______________" << endl;
    for (pair <int, int> p : m)
    {
        cout << p.first << " -> "  << p.second << " | ";
    }
    cout << endl;
    cout << "______________" << endl;
}

void print_int_char_map(map <int, char> m)
{
    cout << "______________" << endl;
    for (pair <int, char> p : m)
    {
        cout << p.first << " -> "  << p.second << " | ";
    }
    cout << endl;
    cout << "______________" << endl;
}


void print_int_s_map(map <int, string >m)
{
    cout << "______________" << endl;
    for (pair <int, string> p : m)
    {
        cout << p.first << " -> " << p.second << " | ";
    }
    cout << endl;
    cout << "______________" << endl;
}
