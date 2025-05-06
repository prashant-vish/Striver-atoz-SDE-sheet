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
// time complexity  O(2*n)
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
    while (temp)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}


// optimal Solution 
// time complexity - O(n)
// space complexity - )(1)

Node* sortList(Node *head){
    // Write your code here.
    if(!head || !head->next) return head;

    Node * temp=head;
    Node * zeroHead=new Node(-1);
    Node * oneHead=new Node(-1);
    Node * twoHead=new Node(-1);
    Node *zero=zeroHead;
    Node *one=oneHead;
    Node *two=twoHead;

    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }

    zero->next=(oneHead->next)?oneHead->next:twoHead->next;
    one->next=twoHead->next;
    two->next=NULL;

    Node * newHead=zeroHead->next;
    delete oneHead;
    delete zeroHead;
    delete twoHead;
    return newHead;
    
}