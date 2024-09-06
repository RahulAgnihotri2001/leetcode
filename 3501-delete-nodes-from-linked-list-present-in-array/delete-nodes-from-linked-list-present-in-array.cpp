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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        while(head!=NULL && st.find(head->val)!=st.end()){
            head=head->next;
        }
        ListNode* temp=head;
        while(temp->next !=NULL){
            if(st.find(temp->next->val)!=st.end()){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};