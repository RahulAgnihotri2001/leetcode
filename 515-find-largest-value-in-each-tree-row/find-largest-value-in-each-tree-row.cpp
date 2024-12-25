/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> pq;
        vector<int> answer;
        if(root==NULL){
            return answer;
        }
        pq.push(root);
        pq.push(NULL);
        
        int n =INT_MIN;
        while(!pq.empty()){
            TreeNode* temp = pq.front();
            pq.pop();
            if(temp!=NULL){
                n=max(n,temp->val);
                if(temp->left){
                    pq.push(temp->left);
                }
                if(temp->right){
                    pq.push(temp->right);
                }
            }
            else{
                answer.push_back(n);
                if(!pq.empty()){
                    n=INT_MIN;
                    pq.push(NULL);
                }
                
            }
        }
        return answer;
    }
};