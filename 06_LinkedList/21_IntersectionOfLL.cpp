#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute force
// time complexity - O(m+n*logm)
// space complexity - O(max(n,m))
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        unordered_map<ListNode *, bool> mpp;
        ListNode *temp = headA;

        while (temp)
        {
            mpp[temp] = true;
            temp = temp->next;
        }
        temp = headB;

        while (temp)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

// Better solution
// time complexity - O(n+m+abs(n-m)+)
// space complexity - O(1)

class Solution
{
public:
    int lengthOfList(ListNode *head)
    {
        if (!head)
        {
            return 0;
        }
        int count = 0;

        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        int l1 = lengthOfList(headA);
        int l2 = lengthOfList(headB);

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        int diff = 0;
        if (l1 > l2)
        {
            diff = l1 - l2;
            while (diff--)
            {
                tempA = tempA->next;
            }
        }
        else
        {
            diff = l2 - l1;
            while (diff--)
            {
                tempB = tempB->next;
            }
        }

        while (tempA && tempB)
        {
            cout << 1 << " ";
            if (tempA == tempB)
            {
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};

// Optimal Solution
// time complexity = O(n)
// space complexity = O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        while (tempA || tempB)
        {
            if (tempA == tempB)
            {
                return tempA;
            }
            if (!tempA)
            {
                tempA = headB;
                tempB = tempB->next;
            }
            else if (!tempB)
            {
                tempB = headA;
                tempA = tempA->next;
            }
            else
            {
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
        return nullptr;
    }
};