#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *deleteAllOccurrences(Node *head, int k)
{
    if (!head)
    {
        return nullptr;
    }
    if (!head->next)
    {
        if (head->data == k)
        {
            delete head;
            return nullptr;
        }
        return head;
    }
    Node *curr = head;

    while (curr)
    {
        if (curr->data == k)
        {
            Node *front = curr->prev;
            Node *Next = curr->next;
            if (curr == head)
            {
                head = head->next;
            }
            if (Next)
                Next->prev = front;
            if (front)
                front->next = Next;
            delete curr;
            curr = Next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
