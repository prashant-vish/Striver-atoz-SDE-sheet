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
// brute  force soluiton
// time complexity - O(n)
// space complexity -O(n)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> vec;
        ListNode *temp = head;
        while (temp)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        int j = vec.size() - 1;

        while (i < vec.size() / 2)
        {
            if (vec[i] != vec[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// Optimal solution
// time complexity - O(n)
// space complexity - O(1)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *nextNode = current->next;

        while (current)
        {
            current->next = prev;
            prev = current;
            current = nextNode;
            if (nextNode)
            {
                nextNode = nextNode->next;
            }
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseList(slow->next);
        ListNode *first = head;
        ListNode *second = newHead;
        while (second)
        {
            if (first->val != second->val)
            {
                reverseList(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseList(newHead);
        return true;
    }
};