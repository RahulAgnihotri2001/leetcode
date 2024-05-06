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
    ListNode* removeNodes(ListNode* head) {
        // step 1 Reverse the linklist
        ListNode* pre=NULL;
        ListNode* curr=head;
        ListNode* ne=head->next;
        while(ne!=NULL){
            curr->next=pre;
            pre=curr;
            curr=ne;
            ne=ne->next;
        }
        curr->next=pre;
        ListNode* temp=curr;
        int ma=curr->val;
        while(temp->next!=NULL){
            if(temp->next->val < ma){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
                ma=temp->val;
            }
        }
        pre=NULL;
        ne=curr->next;
        while(ne!=NULL){
            curr->next=pre;
            pre=curr;
            curr=ne;
            ne=ne->next;
        }
        curr->next=pre;
        return curr;
    }
};