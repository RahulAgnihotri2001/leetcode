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

    void preorder(string &temp,string &answer,TreeNode* root){
        temp.push_back('a'+root->val);
        if(root->left ==NULL && root->right==NULL){
            reverse(temp.begin(),temp.end());
            if(temp<answer){
                answer=temp;
            }
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            return;
        }
        if(root->left){
            preorder(temp,answer,root->left);
        }
        if(root->right){
            preorder(temp,answer,root->right);
        }
        temp.pop_back();
    }


    string smallestFromLeaf(TreeNode* root) {
        string answer="";
        TreeNode* temp= root;
        while(temp!=NULL){
            answer.push_back('a'+temp->val);
            if(temp->left){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        
        reverse(answer.begin(),answer.end());
        cout<<answer;
        // do preorder traversal;
        string tem="";
        preorder(tem,answer,root);
        return answer;
        
    }
};