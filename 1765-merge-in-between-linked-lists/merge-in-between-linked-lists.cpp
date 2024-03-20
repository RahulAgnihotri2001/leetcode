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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Get Pointer to the end of list2
        ListNode* end2=list2;
        while(end2!=NULL && end2->next){
            end2=end2->next;
        }
        ListNode* temp=list1;
        for(int i=1;i<a;i++){
            temp=temp->next;
        }
        ListNode* temp2=temp->next;
        //cout<<"temp val "<<temp->val<<endl;
        temp->next=list2;
        for(int i=0;i<(b-a);i++){
            ListNode* x=temp2;
            temp2=temp2->next;
            delete x;
        }
        end2->next=temp2->next;
        delete temp2;
        return list1;
    }

};