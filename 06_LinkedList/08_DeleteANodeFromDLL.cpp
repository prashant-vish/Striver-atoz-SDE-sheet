#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution
{
public:
    // Function to delete a node at given position.
    Node *deleteNode(Node *head, int x)
    {
        // Your code
        if (x == 1)
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return head;
        }

        int count = 1;
        Node *traverse = head;
        while (x != count)
        {
            traverse = traverse->next;
            count++;
        }
        Node *phlewala = traverse->prev;
        phlewala->next = traverse->next;
        if (traverse->next)
        {
            traverse->next->prev = phlewala;
        }
        delete traverse;
        return head;
    }
};