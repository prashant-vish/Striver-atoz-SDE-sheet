#include <bits/stdc++.h>
using namespace std;

// Time complexity -O(n)
// Space complexity - O(n)

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = nullptr;
        data = 0;
        next = nullptr;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};
class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {

        int n = arr.size();

        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node(arr[i]);
            temp->prev = prev;
            prev->next = temp;
            prev = prev->next;
        }
        return head;
    }
};