#include <bits/stdc++.h>
using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute force solution
// time complexity -O(2*n)
// space compelxity O(n)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        stack<int> st;

        ListNode *traverse = head;

        while (traverse)
        {
            st.push(traverse->val);
            traverse = traverse->next;
        }
        traverse = head;
        while (!st.empty())
        {
            traverse->val = st.top();
            traverse = traverse->next;
            st.pop();
        }
        return head;
    }
};


// Optimal solution
// time complexity = O(n);
//  space complexity -O(1)
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextNode = current->next;

        while (current)
        {
            current->next = prev;
            prev = current;
            current = nextNode;
            if (nextNode)
            {
                nextNode = nextNode->next;
            }
        }
        return prev;
    }
};