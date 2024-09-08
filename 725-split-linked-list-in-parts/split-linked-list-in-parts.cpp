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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>  answer;
        if(head==NULL){
            for(int i=0;i<k;i++){
                answer.push_back(NULL);
            }
            return answer;
        }
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int a=count/k;
        if(a==0){
            temp=head;
            int a=0;
            while(temp!=NULL){
                answer.push_back(temp);
                 ListNode* t=temp->next;
                 temp->next=NULL;
                 temp=t;
                a++;
                //temp=temp->next;
            }
            while(a<k){
                answer.push_back(NULL);
                a++;
            }
            return answer;
        }
        if(k*a!=count){
            a++;
        }
        int x=k*(1-a)+count;
        int y=k*a-count;
        // x of size a;
        // y of size a-1;
        cout<<x<<"/"<<count<<"/"<<a<<" --"<<k<<"/"<<y;
        temp=head;
        for(int i=0;i<x;i++){
            answer.push_back(temp);
            for(int j=0;j<a-1;j++){
                temp=temp->next;
            }
            ListNode* t=temp->next;
                 temp->next=NULL;
                 temp=t;
        }
        for(int i=0;i<y;i++){
            answer.push_back(temp);
            for(int j=0;j<(a-1)-1;j++){
                temp=temp->next;
            }
            ListNode* t=temp->next;
                 temp->next=NULL;
                 temp=t;
        }
        return answer;
    }
};
