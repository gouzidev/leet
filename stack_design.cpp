#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include<algorithm>

using namespace std;

void print_vec(vector <int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
    cout << endl;
}
void print_set(multiset <int> s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << " -> " << *it << " | ";
    }
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


class MinStack {
    private :
    typedef struct s_stack
    {
        int val;
        struct s_stack *next;
    }  t_stack;
    multiset <int> sorted;
public:
    t_stack *head;
    int min_val;
    MinStack()
    {
        head = NULL;
        min_val = __INT_MAX__;
    }
    
    void push(int val)
    {
        t_stack *new_node = new t_stack;
        new_node->next = NULL;
        if (head)
            new_node->next = head;
        new_node->val = val;
        head = new_node;
        sorted.insert(val);
        min_val = *sorted.begin();
        cout << "push set -> " << val << "    ";
        print_set(sorted);
    }
    
    void pop()
    {
        t_stack *removed;
        removed = head;
        if (head)
        {
            sorted.erase(sorted.find(removed->val));
            head = head->next;
        }
        cout << "pop  set -> " << removed->val << "    ";
        print_set(sorted);
        delete(removed);
        if (!sorted.empty())
        {
            cout << "sorted =  ";
            print_set(sorted);
            min_val = *sorted.begin();
        }
        else
            min_val = 0;
    }
    
    int top() {
        if (head)
            return head->val;
        return __INT_MAX__;
    }
    
    int getMin() {
        return min_val;
    }
};


int main() {
    // Create test cases
    
    MinStack minStack = MinStack();
    minStack.push(0);
    minStack.push(1);
    minStack.push(0);
    cout <<  minStack.getMin() << endl; // return -3
    minStack.pop();
    cout << minStack.getMin() << endl; // return -2
}
