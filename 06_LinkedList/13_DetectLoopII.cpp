#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute force -
// time complexity - O(n (logn))
// space complexity -O(n)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        unordered_map<ListNode *, bool> mpp;
        ListNode *traverse = head;

        while (traverse)
        {
            auto valu = mpp.find(traverse);
            if (valu != mpp.end())
            {
                return traverse;
            }
            mpp[traverse] = true;
            traverse = traverse->next;
        }
        return NULL;
    }
};

// brute force -
// time complexity - O(n)
// space complexity -O(n)

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};