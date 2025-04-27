#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
// Brute force Approach
// Time Complexity - O(2*n)
// Space Complexity - O(n)
class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        // Your code here
        stack<int> st;
        DLLNode *traverse = head;
        while (traverse)
        {
            st.push(traverse->data);
            traverse = traverse->next;
        }
        traverse = head;
        while (!st.empty())
        {
            traverse->data = st.top();
            traverse = traverse->next;
            st.pop();
        }

        return head;
    }
};

// Optimal Solution
// Time complexity -> O(n)
// Space complexity -> O(1)

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        // Your code here
        DLLNode *current = head;
        DLLNode *nextNode = head->next;

        while (nextNode)
        {
            current->next = current->prev;
            current->prev = nextNode;

            current = nextNode;
            nextNode = current->next;
        }
        current->next = current->prev;
        current->prev = nextNode;

        return current;
    }
};
