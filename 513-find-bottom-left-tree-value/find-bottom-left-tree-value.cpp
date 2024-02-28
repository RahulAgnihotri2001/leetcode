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

    void traversal(TreeNode* root,int &answer,int &height,int temp){
        if(root==NULL){
            return;
        }
        if(root->right){
            temp++;
            traversal(root->right,answer,height,temp);
            temp--;
        }
        if(temp>=height){
            height=temp;
            //cout<<height<<"-"<<root->val<<endl;
            answer=root->val;
        }
        if(root->left){
            temp++;
            traversal(root->left,answer,height,temp);
            temp--;
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        int height=0;
        int answer=root->val;
        int temp_height=0;
        traversal(root,answer,height,temp_height);
        return answer;
    }
};