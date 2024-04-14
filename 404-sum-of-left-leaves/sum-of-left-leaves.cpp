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

    void fs(TreeNode* root , int &sum){
        if(root==NULL || (root->left==NULL && root->right==NULL) ){
            return;
        }
        if(root->left){
            if(root->left->left==NULL && root->left->right==NULL){
                sum = sum+root->left->val;
            }
            else{
                fs(root->left,sum);
            }
        }
        if(root->right){
            fs(root->right,sum);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int sum=0;
        fs(root,sum);
        return sum;
    }
};