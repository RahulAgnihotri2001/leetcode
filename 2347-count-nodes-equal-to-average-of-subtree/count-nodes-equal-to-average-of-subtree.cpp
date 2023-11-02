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
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int leftheight=0 ,rightheight=0;
        int lc=0,rc=0;
        int answer=0;
        fun(root->left,leftheight,lc,answer);
        fun(root->right,rightheight,rc,answer);
        int x=(leftheight+rightheight+root->val)/(lc+rc+1);
        if(x==root->val){
            answer++;
        }
        return answer;
    }

    void fun(TreeNode* root, int &sum,int &count,int &answer){
        if(root==NULL){
            return;
        }
        int leftheight=0 ,rightheight=0;
        int lc=0,rc=0;
        fun(root->left,leftheight,lc,answer);
        fun(root->right,rightheight,rc,answer);
        int x=(leftheight+rightheight+root->val)/(lc+rc+1);
        if(x==root->val){
            answer++;
        }
        sum=leftheight+rightheight+root->val;
        count=lc+rc+1;
        return;
    }
};