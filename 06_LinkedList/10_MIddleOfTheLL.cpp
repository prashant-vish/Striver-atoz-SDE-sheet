
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force
// time complexity O(n+n/2)
// space complexity O(1)

class Solution
{

public:
    int findLength(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *middleNode(ListNode *head)
    {
        int len = findLength(head);
        int num = len / 2;
        ListNode *traverse = head;
        while (num)
        {
            traverse = traverse->next;
            num--;
        }
        return traverse;
    }
};

// Optimal Approach -
// time complexity O(n/2)
// space complexity O(1)

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next)
            {
                fast = fast->next;
            }
        }
        return slow;
    }
};