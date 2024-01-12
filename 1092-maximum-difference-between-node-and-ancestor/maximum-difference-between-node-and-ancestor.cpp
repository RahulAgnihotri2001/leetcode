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

    void fun(TreeNode* root,int &ans,int ma,int mi){
        ans=max(ans,max(abs(root->val-ma),abs(root->val-mi)));
        ma=max(ma,root->val);
        mi=min(mi,root->val);
        if(root->left){
            fun(root->left,ans,ma,mi);
        }
        if(root->right){
            fun(root->right,ans,ma,mi);
        }
        return;
    }


    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        if(root==NULL){
            return ans;
        }
        int ma=root->val;
        int mi=root->val;
        if(root->left){
            fun(root->left,ans,ma,mi);
        }
        if(root->right){
            fun(root->right,ans,ma,mi);
        }
        return ans;
    }
};