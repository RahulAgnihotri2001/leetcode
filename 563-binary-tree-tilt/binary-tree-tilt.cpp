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
    int fun(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int le=0;
        int ri=0;
        if(root->left){
            le=fun(root->left);
        }
        if(root->right){
            ri=fun(root->right);
        }
        root->val=root->val+le+ri;
        return root->val;
    }

    void preorder(TreeNode* root,int& answer){
        int le=0;
        int re=0;
        if(root->left){
            le=root->left->val;
        }
        if(root->right){
            re=root->right->val;
        }
        answer=answer+abs(le-re);
        if(root->left)
        preorder(root->left,answer);
        if(root->right)
        preorder(root->right,answer);
        return;
    }

    int findTilt(TreeNode* root) {
        // Replace the node with sum of lower tree and the node
        // pre order traversal to calculate total answer;
        if(root==NULL){
            return 0;
        }
        int x = fun(root);
        int answer=0;
        preorder(root,answer);
        return answer;

    }
};