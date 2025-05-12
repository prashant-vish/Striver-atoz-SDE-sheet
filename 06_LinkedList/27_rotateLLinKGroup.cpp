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

// Brute Force / Optimal Approach
// Time complexity - O(n+n)
// space complexity - O(1)
class Solution {
    public:
         ListNode* reverseList(ListNode* head) {
            if(!head) return head;
            ListNode* prev=nullptr;
            ListNode* current=head;
            ListNode* nextNode=current->next;
    
            while(current){
                current->next=prev;
                prev=current;
                current=nextNode;
                if(nextNode){
                    nextNode=nextNode->next;
                }
            }
            return prev;
        }
        ListNode* getkthNode(ListNode *temp, int k){
    
            k=k-1;
            while(temp && k>0){
                k--;
                temp=temp->next;
            }
            return temp;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head || !head->next) return head;
    
            ListNode *temp=head;
            ListNode *prevLast=nullptr;
    
            while(temp){
                ListNode *kthNode=getkthNode(temp,k);
                if(!kthNode){
                    if(prevLast){
                        prevLast->next=temp;
                    }
                    break;
                }
                ListNode *nextNode=kthNode->next;
                kthNode->next=nullptr;
                reverseList(temp);
                if(temp==head){
                    head=kthNode;
                }else{
                    prevLast->next=kthNode;
                }
                prevLast=temp;
                temp=nextNode;
            }
            return head;
        }
    };