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
    void inorder(TreeNode* root,priority_queue<int> &pq){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(pq.empty()){
                pq.push(root->val);
            }
            else if(pq.size()==1 && pq.top()!=root->val){
                 pq.push(root->val);
            }
            else if(pq.top()>root->val){
                int x=pq.top();
                pq.pop();
                if(pq.top()==root->val){
                    pq.push(x);
                }
                else
                pq.push(root->val);
            }
            return;
        }
        if(root->left){
            inorder(root->left,pq);
        }
        if(root->right){
            inorder(root->right,pq);
        }
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        priority_queue<int> pq;
        inorder(root,pq);
        if(pq.size()==2){
            return pq.top();
        }
        return -1;
        
        
    }
};