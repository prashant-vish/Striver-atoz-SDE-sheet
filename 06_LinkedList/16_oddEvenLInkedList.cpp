

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// time complexity -O(n)
// space complexity -O(1)
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *tail = head->next;
        ListNode *first = head;
        ListNode *second = head->next;

        while (second && second->next)
        {
            first->next = second->next;
            first = first->next;
            second->next = second->next->next;
            second = second->next;
        }
        first->next = tail;
        return head;
    }
};