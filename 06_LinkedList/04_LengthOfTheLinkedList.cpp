struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node *head)
    {

        int count = 0;

        Node *temp = head;

        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
};
