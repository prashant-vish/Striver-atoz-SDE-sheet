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
    ListNode *deleteMiddle(ListNode *head)
    {

        if (!head->next)
        {
            head = head->next;
            delete head;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = nullptr;
        while (fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = slow->next;
        delete slow;
        return head;
    }
};