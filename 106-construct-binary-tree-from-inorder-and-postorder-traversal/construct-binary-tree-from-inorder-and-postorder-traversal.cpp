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

    int find(vector<int> &inorder ,int curr,int start,int end){
        for(int i=start ;i<=end;i++){
            if(inorder[i]==curr){
                return i;
            }
        }
        return -1;
    }

    TreeNode* bt(int &index,int start,int end ,vector<int>& inorder, vector<int>& postorder){
        if(start>end){
            return NULL;
        }
        int curr=postorder[index];
        index--;
        TreeNode* temp=new TreeNode(curr);
        if(start==end){
            return temp;
        }
        int pos=find(inorder,curr,start,end);
        temp->right=bt(index,pos+1,end,inorder,postorder);
        temp->left=bt(index,start,pos-1,inorder,postorder);
        return temp;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        TreeNode* temp = bt(index,0,postorder.size()-1,inorder,postorder);
        return temp;
    }
};