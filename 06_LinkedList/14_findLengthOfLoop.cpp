#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};

// bruteforce Approach
// time-complexity - O(n)
// space complexity -O(n)
int lengthOfLoop(Node *head)
{

    unordered_map<Node *, int> mpp;

    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        if (mpp.find(temp) != mpp.end())
        {
            return count - mpp[temp];
        }
        mpp[temp] = count;
        temp = temp->next;
    }

    return 0;
}

// Optimal Solution
// time complexity -O(n)
// space complexity -O(1)

int lengthOfLoop(Node *head)
{

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {

        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int count = 1;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                count++;
            }
            return count;
        }
    }

    return 0;
}
