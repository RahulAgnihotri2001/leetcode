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

    void func(vector<TreeNode*> &vec){
        int start=0;
        int end=vec.size()-1;
        while(start<end){
            int a=vec[start]->val;
            vec[start]->val=vec[end]->val;
            vec[end]->val=a;
            start++;
            end--;
        }
        return;
    }


    TreeNode* reverseOddLevels(TreeNode* root) {
        // levelorder traversal approch
        queue<TreeNode*> dq;
        int level=0;
        dq.push(root);
        dq.push(NULL);
        vector<TreeNode*> temp;
        while(!dq.empty()){
            TreeNode* te=dq.front();
            dq.pop();
            if(te!=NULL){
                if(level%2==1){
                    temp.push_back(te);
                }
                if(te->left){
                    dq.push(te->left);
                }
                if(te->right){
                    dq.push(te->right);
                }
            }
            else{
                if(level%2==1){
                    func(temp);
                }
                temp.clear();
                level++;
                if(!dq.empty()){
                    dq.push(NULL);
                }
            }
        }
        return root;
    }
};