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

// brute force solution
// time complexity - O(n*n)
// space complexity -O(1)

vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;

    Node *temp = head;

    while (temp)
    {

        Node *temp2 = temp->next;
        while (temp2)
        {
            int value = temp->data + temp2->data;
            if (value == k)
            {
                ans.push_back({temp->data, temp2->data});
                temp2 = temp2->next;
                break;
            }
            else if (value < k)
            {
                temp2 = temp2->next;
            }
            else
            {
                break;
            }
        }
        temp = temp->next;
    }

    return ans;
}

// optimal solution
// time complexity - O(n)
// space complexity -O(1)
vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;

    Node *frontNode = head;
    Node *backNode = head;
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    backNode = temp;
    while (frontNode->data < backNode->data)
    {

        int value = frontNode->data + backNode->data;
        if (value == k)
        {
            ans.push_back({frontNode->data, backNode->data});
            frontNode = frontNode->next;
            backNode = backNode->prev;
        }
        else if (value < k)
        {
            frontNode = frontNode->next;
        }
        else
        {
            backNode = backNode->prev;
        }
    }

    return ans;
}
