/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start=head;
        ListNode* current=head;
        ListNode* new_start=NULL;
        ListNode* new_end=NULL;

        int index=1;
        int count=0;

        if(head->next==NULL){
            return head;
        }

        while(start!=NULL && count<k){
            count++;
            start=start->next;
        }
        
        if(start==NULL && count<k){
            return head;
        }
        
        index=1;
        
        while(current->next!=NULL & index<=k){
            ListNode* next=current->next;
            if(new_start==NULL){
                new_end=current;
            }
            cout<<current->val<<endl;
            current->next=new_start;
            new_start=current;
            current=next;
            index++;
        }
        
        if(current->next==NULL && index==k){
            current->next=new_start;
            new_start=current;
            return new_start;
        }

        
        new_end->next=reverseKGroup(current,k);
        
        return new_start;

    }
};