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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> answer;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(-1);
            }
            answer.push_back(temp);
        }
        int right=n-1 , down=m-1, left=0, top=1;
        int x=0 , y=0;
        ListNode* temp=head;
        while(temp!=NULL){
            // Go right
            while(temp!=NULL && y<=right){
                answer[x][y]=temp->val;
                temp=temp->next;
                y++;
            }
            y--;
            x++;
            right--;
            // Go down
            while(temp!=NULL && x<=down){
                answer[x][y]=temp->val;
                temp=temp->next;
                x++;
            }
            x--;
            y--;
            down--;
            // Go Left
            while(temp!=NULL && y>=left){
                answer[x][y]=temp->val;
                temp=temp->next;
                y--;
            }
            y++;
            x--;
            left++;
            // Go Top
            while(temp!=NULL && x>=top){
                answer[x][y]=temp->val;
                temp=temp->next;
                x--;
            }
            y++;
            x++;
            top++;
        }
        return answer;
    }
};