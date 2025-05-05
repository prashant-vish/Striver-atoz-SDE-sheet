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

// Brute force Approach
// time complexity - O(n*log(n))
// space complexity - O(n)
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        vector<int> vec;
        ListNode *traverse = head;

        while (traverse)
        {
            vec.push_back(traverse->val);
            traverse = traverse->next;
        }

        sort(vec.begin(), vec.end());
        traverse = head;
        int i = 0;
        while (traverse)
        {
            traverse->val = vec[i++];
            traverse = traverse->next;
        }
        return head;
    }
};
// Optimal Approach

// time complexity O(log(n)*(n+n/2))
// space complexity O(logn)-- stack space 


class Solution
{
public:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *mergeLL(ListNode *list1, ListNode *list2)
    {

        ListNode *dummyNode = new ListNode(-1);
        ListNode *temp = dummyNode;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if (list1)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }
        return dummyNode->next;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *middle = findMiddle(head);
        ListNode *leftHead = head;
        ListNode *rightHead = middle->next;
        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeLL(leftHead, rightHead);
    }
};