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
    ListNode* deleteDuplicates(ListNode* head) {
            
        ListNode* new_head=NULL;
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* last_done=NULL;
        int current_duplicate_val=-200;
        
        if(head==NULL){
            return NULL;
        }
        
        
        while(current->next!=NULL){
            if(current->val==current->next->val || current->val==current_duplicate_val){

                current_duplicate_val=current->val;
                ListNode* t=current->next;
                delete(current);
                current=t;
                
            }else{
                cout<<current->val<<endl;
                ListNode* t=current->next;
                current->next=NULL;
                if(new_head==NULL){
                    new_head=current;
                    last_done=current;
                }else{
                    last_done->next=current;
                    last_done=last_done->next;
                }
                current=t;
            }
            
        }
        
        if(current->next==NULL && current->val!=current_duplicate_val){
            if(new_head==NULL){
                new_head=current;
            }else{
            last_done->next=current;
            }
        }
        
        return new_head;
    }
};