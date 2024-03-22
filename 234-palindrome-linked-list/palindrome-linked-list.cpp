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
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        if(head->next==NULL){
            return true;
        }
        int count=0;
        ListNode* temp1=head;
        while(temp1!=NULL){
            count++;
            temp1=temp1->next;
        }
        int x=count/2-1;
        temp1=head;
        while(x!=0){
            x--;
            temp1=temp1->next;
        }
        ListNode* temp2=temp1->next;
        ListNode* pre=NULL;
        ListNode* ne=temp2->next;
        while(ne!=NULL){
            temp2->next=pre;
            pre=temp2;
            temp2=ne;
            ne=ne->next;
        }
        temp2->next=pre;
        temp1->next=temp2;
        temp1=head;
        for(int i=0;i<count/2;i++){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};