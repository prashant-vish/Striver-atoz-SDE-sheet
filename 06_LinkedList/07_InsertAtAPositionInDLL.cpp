#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

// Function to insert a new node at given position in doubly linked list.
class Solution
{
public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data)
    {

        int count = 0;
        Node *traverse = head;

        while (count != pos)
        {
            traverse = traverse->next;
            count++;
        }
        Node *newNode = new Node(data);
        Node *nextwala = traverse->next;

        traverse->next = newNode;
        newNode->prev = traverse;
        if (nextwala)
        {
            newNode->next = nextwala;
            nextwala->prev = newNode;
        }
        return head;
    }
};