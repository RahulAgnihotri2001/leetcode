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

    void func(TreeNode* root,int height,int val,int depth){
        if(height>=depth || root==NULL){
            return;
        }
        if(height==depth-1){
            TreeNode* temp1=root->left;
            TreeNode* temp2=root->right;
            TreeNode* lroot=new TreeNode(val);
            lroot->left=temp1;
            TreeNode* rroot=new TreeNode(val);
            rroot->right=temp2;
            root->left=lroot;
            root->right=rroot;
            return;
        }
        if(root->left){
            func(root->left,height+1,val,depth);
        }
        if(root->right){
            func(root->right,height+1,val,depth);
        }

    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL){
            return root;
        }
        if(depth==1){
            TreeNode* nroot=new TreeNode(val);
            nroot->left=root;
            return nroot;
        }
        int height=1;
        func(root,height,val,depth);
        return root;
    }
};