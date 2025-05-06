#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

// brute force
// time complexity  O(n)
// space complexity O(1)
Node *sortList(Node *head)
{
    // Write your code here.
    if (!head || !head->next)
        return head;
    Node *temp = head;

    int count0 = 0, count1 = 0, count2 = 0;
    while (temp)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;
        temp = temp->next;
    }
    temp = head;
    while (count0)
    {
        temp->data = 0;
        count0--;
        temp = temp->next;
    }
    while (count1)
    {
        temp->data = 1;
        count1--;
        temp = temp->next;
    }
    while (count2)
    {
        temp->data = 2;
        count2--;
        temp = temp->next;
    }
    return head;
}