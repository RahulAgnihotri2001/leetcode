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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        //count-n tak jao    next delete karo
        if(count-n<=0 && count<=1){
            return NULL;
        }
        else if(count-n==0){
            ListNode* d=head;
            head=head->next;
            return head;
        }
        temp=head;
        int index=1;
        while(index!=count-n){
            index++;
            temp=temp->next;
        }
        ListNode* d=temp->next;
        temp->next=temp->next->next;
        delete d;
        return head;
    }
};