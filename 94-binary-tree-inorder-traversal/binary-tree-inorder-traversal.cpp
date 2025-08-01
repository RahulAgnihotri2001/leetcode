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

    void inot(TreeNode* root, vector<int> &vec){
        if(root==NULL){
            return;
        }
        inot(root->left,vec);
        vec.push_back(root->val);
        inot(root->right,vec);
        return;
    }


    vector<int> inorderTraversal(TreeNode* root) {
        // Left , mid , right ;
        vector<int> answer; 
        inot(root,answer);
        return answer;
    }
};