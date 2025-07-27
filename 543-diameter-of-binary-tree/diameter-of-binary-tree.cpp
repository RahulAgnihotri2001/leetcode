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

    int func(TreeNode* root, int &height){
        if(root==NULL){
            return 0;
        }
        int lh =0;
        int rh =0;
        int a = func(root->left,lh);
        int b= func(root->right,rh);
        height = max(lh,rh)+1;
        return max(lh+rh+1, max(a,b));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int height=0;
        int answer = func(root,height);
        return answer-1;
    }
};