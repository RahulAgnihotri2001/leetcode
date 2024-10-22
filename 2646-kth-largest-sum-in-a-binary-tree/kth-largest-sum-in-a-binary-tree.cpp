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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // We need a queue 
        queue<TreeNode*> qu;
        priority_queue<long long> pq;
        qu.push(root);
        qu.push(NULL);
        long long tempsum=0;
        while(!qu.empty()){
            TreeNode* temp=qu.front();
            qu.pop();
            if(temp==NULL){
                pq.push(tempsum);
                tempsum=0;
                if(qu.empty()){
                    break;
                }
                else{
                    qu.push(NULL);
                }
            }
            else{
                tempsum=tempsum+temp->val;
                if(temp->left)
                    qu.push(temp->left);
                if(temp->right)
                    qu.push(temp->right);
            }
        }
        while(k!=1 && !pq.empty()){
            pq.pop();
            k--;
        }
        if(pq.empty()){
            return -1;
        }
        else{
            return pq.top();
        }
    }
};