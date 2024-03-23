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
    void reorderList(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count==1 || count==2){
            return;
        }
        if(count%2==1){
            count=count/2+1;
        }
        else{
            count=count/2;
        }
        //cout<<count<<endl;
        int index=0;
        temp=head;
        while(index!=count-1){
            temp=temp->next;
            index++;
        }
        //cout<<temp->val<<endl;
        ListNode* prev=NULL;
        ListNode* curr=temp->next;
        ListNode* ne=curr->next;
        while(ne!=NULL){
            curr->next=prev;
            prev=curr;
            curr=ne;
            ne=ne->next;
        }
        curr->next=prev;
        //cout<<curr->val<<endl;
        temp->next=NULL;
        temp=head;
        cout<<curr->val<<endl;
        while(curr!=NULL){
            ListNode* p1=temp->next;
            temp->next=curr;
            temp=p1;
            p1=curr->next;
            curr->next=temp;
            curr=p1;
        }
        return ;
    }
};