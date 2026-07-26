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
    bool isValidBST(TreeNode* root) {
        // If inorder in asscending the BST;
        vector<int> vec;
        iot(root,vec);
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i]>=vec[i+1]){
                return false;
            }
        }
        return true;
    }

    void iot(TreeNode* root, vector<int> &vec){
        if(root==NULL){
            return;
        }
        iot(root->left,vec);
        vec.push_back(root->val);
        iot(root->right,vec);
    }

};