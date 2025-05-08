#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// brute force
// time complexity O(max (l1, l2))
// space complexity O(max(l1,l2))
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *dummyNode = new ListNode(-1);
        ListNode *d = dummyNode;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int carry = 0;

        while (t1 && t2)
        {
            ListNode *temp = new ListNode(-1);
            temp->val = t1->val + t2->val + carry;
            if (temp->val < 10)
            {
                carry = 0;
            }
            else
            {
                temp->val = temp->val % 10;
                carry = 1;
            }
            d->next = temp;
            d = d->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while (t1)
        {
            ListNode *temp = new ListNode(-1);
            temp->val = t1->val + carry;
            if (temp->val < 10)
            {
                carry = 0;
            }
            else
            {
                temp->val = temp->val % 10;
                carry = 1;
            }
            d->next = temp;
            d = d->next;
            t1 = t1->next;
        }
        while (t2)
        {
            ListNode *temp = new ListNode(-1);
            temp->val = t2->val + carry;
            if (temp->val < 10)
            {
                carry = 0;
            }
            else
            {
                temp->val = temp->val % 10;
                carry = 1;
            }
            d->next = temp;
            d = d->next;
            t2 = t2->next;
        }
        if (carry)
        {
            ListNode *temp = new ListNode(carry);
            d->next = temp;
        }
        return dummyNode->next;
    }
};

// time complexity - O(max (l1,l2))
// space complexity -O(max (l1,l2))

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};