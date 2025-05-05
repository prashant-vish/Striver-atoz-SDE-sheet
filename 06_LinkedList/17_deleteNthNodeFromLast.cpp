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
class Solution {
    public:
        ListNode* deleteNode(ListNode * head,int n){
    
            if(n==1){
                ListNode*temp=head;
                head=head->next;
                delete temp;
                return head;
            }
            ListNode *prev=nullptr;
            ListNode *curr=head;
            int count=0;
            while(curr){
                count++;
                if(count==n){
                    prev->next=curr->next;
                    delete curr;
                    break;
                }
                prev=curr;
                curr=curr->next;
            }
            return head;
        }
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            
            ListNode *traverse=head;
            int totalNode=0;
            while(traverse){
                traverse=traverse->next;
                totalNode++;
            }
            int delNode=totalNode-n+1;
            return deleteNode(head,delNode);
        }
    };