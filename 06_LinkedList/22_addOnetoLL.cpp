#include <bits/stdc++.h>
using namespace std;

// brute force apporach
// time complexity -O(3*n)
// space complexity -O(1)

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
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

Node *reverseL(Node *head)
{

    Node *prev = NULL;
    Node *curr = head;
    Node *Next = head->next;

    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = Next;
        if (Next)
            Next = Next->next;
    }
    return prev;
}
Node *addOne(Node *head)
{
    if (!head)
    {
        Node *t = new Node(1);
        return t;
    }

    head = reverseL(head);
    Node *temp = head;
    int carry = 1;

    while (temp)
    {
        temp->data = temp->data + carry;
        if (temp->data >= 10)
        {
            temp->data = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
            break;
        }
        temp = temp->next;
    }
    head = reverseL(head);
    if (carry)
    {
        Node *t = new Node(carry);
        t->next = head;
        return t;
    }
    return head;
    ;
}
// Optimal solution 
// time complexity -O(n)
// space complexity -O(n) stack space;

int helper(Node *temp){
    if(!temp){
        return 1;
    }
    int carry=helper(temp->next);
    
    temp->data=temp->data+carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node *addOne(Node *head)
{
    if(!head){
        Node *t =new Node(1);
        return t;
    }
    int carry=helper(head);
   
    if(carry){
        Node * t=new Node(carry);
        t->next=head;
        return t;
        
    }
    return head;;
}