#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

class MinStack {
    private :
    typedef struct s_stack
    {
        int val;
        struct s_stack *next;
    }  t_stack;
public:
    t_stack *head;
    MinStack() {head = NULL;}
    
    void push(int val)
    {
        t_stack *new_node = new t_stack;
        new_node->next = NULL;
        if (head)
            new_node->next = head;
        new_node->val = val;
        head = new_node;
    }
    
    void pop()
    {
        t_stack *removed;
        removed = head;
        if (head)
            head = head->next;
        delete(removed);
    }
    
    int top() {
        if (head)
            return head->val;
        return __INT_MAX__;
    }
};

class Solution {
public:
    bool is_op(string s)
    {
        if (s == "*" || s == "/")
            return true;
        else if (s == "+" || s == "-")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int a;
        int b;
        int res;
        MinStack stack;
        for (string s : tokens)
        {
            if (!is_op(s))
                stack.push(atoi(s.c_str()));
            else if (s == "+")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a + b);
            }
            else if (s == "-")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (s == "*")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(a * b);
            }
            else if (s == "/")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
        }
        return stack.top();
    }
};


void printResult(int result) {
    cout << "Result: " << (result) << endl;
}

int main() {
    // Create test cases
    Solution solution;
    vector <string>  strings = {"6","2","+","4","/"};
    // Test case 1
    int result1 = solution.evalRPN(strings);
    cout << "Test Case 1:" << endl;
    printResult(result1);
    
    return 0;
}
