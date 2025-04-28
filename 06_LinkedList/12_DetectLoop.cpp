#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute force Approach
// time-complexity O(log(n))
// space comlexity O(1)

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> mpp;
        ListNode *traverse = head;

        while (traverse)
        {
            if (mpp.find(traverse) != mpp.end())
            {
                return true;
            }
            mpp[traverse] = true;
            traverse = traverse->next;
        }
        return false;
    }
};
// Optimal Approach
// time complexity O(n)
// space complexity O(1)

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(!head) return false;
            ListNode * slow=head;
            ListNode * fast=head->next;
    
            while(fast){
                if(slow==fast) return true;
    
                slow=slow->next;
                fast=fast->next;
                if(fast){
                    fast=fast->next;
                }
            }
            return false;
        }   
    };