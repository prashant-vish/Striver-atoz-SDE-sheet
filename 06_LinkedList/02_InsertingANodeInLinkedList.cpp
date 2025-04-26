#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        // Code here

        if (!head)
        {
            Node *temp = new Node(x);
            return temp;
        }

        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        Node *addNode = new Node(x);
        temp->next = addNode;

        return head;
    }
};