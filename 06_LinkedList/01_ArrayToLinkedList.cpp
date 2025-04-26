#include <bits/stdc++.h>
using namespace std;

// Time complexity= O(n)
// space complexity =O(n)
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
class Solution
{
public:
    Node *constructLL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *traverse = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            traverse->next = temp;
            traverse = temp;
        }
        return head;
    }
};