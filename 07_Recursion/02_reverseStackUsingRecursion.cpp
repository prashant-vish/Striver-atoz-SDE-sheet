#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if (s.size() == 0)
    {
        s.push(x);
        return;
    }
    int value = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(value);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int value = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, value);
}