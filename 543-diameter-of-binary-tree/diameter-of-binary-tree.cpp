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

    int fun(TreeNode* root,int &height){
        if(root==NULL){
            return 0;
        }
        int lh=0;
        int rh=0;
        int ans=0;
        if(root->left){
            ans=fun(root->left,lh);
        }
        if(root->right){
            ans=max(ans,fun(root->right,rh));
        }
        ans=max(ans,lh+rh+1);
        height=1+max(lh,rh);
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int height=0;
        int answer=fun(root,height);
        return answer-1;
    }
};