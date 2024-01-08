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


    int rangeSumBST(TreeNode* root, int low, int high) {
        // do in order traversal
        if(root==NULL){
            return 0;
        }
        int x=0;
        if(root->val<=high && root->val>=low){
            x=root->val;
        }
        return x+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};