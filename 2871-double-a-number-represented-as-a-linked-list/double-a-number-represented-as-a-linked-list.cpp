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

    ListNode* getAns(ListNode* head, int &carry){
        if(head == NULL){
            return head;
        }

        ListNode* midAns = getAns(head->next, carry);
        // double the num on head 
        int newNum = (head->val * 2) + carry;
        carry = newNum / 10;
        newNum = newNum % 10;
        head->val = newNum;
        return head;

    }
public:
    ListNode* doubleIt(ListNode* head) {

        if(head == NULL){
            return head;
        }
        int carry = 0;
        ListNode* newHead = getAns(head, carry);
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = newHead;
            return newNode;
        }
        return newHead;
        
    }
};