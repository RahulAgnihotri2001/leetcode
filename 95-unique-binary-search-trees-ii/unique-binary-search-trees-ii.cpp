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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        ct(1,n,ans);
        return ans;
    }
    void ct(int start, int end, vector<TreeNode*> &ans){
        if(start == end){
            TreeNode* temp = new TreeNode(start);
            ans.push_back(temp);
            return;
        }
        for(int i = start;i<=end;i++){
            vector<TreeNode*> leftpnc;
            vector<TreeNode*> rightpnc;
            if(i-1>=start)
                ct(start,i-1,leftpnc);
            else{
                leftpnc.push_back(NULL);
            }
            if(i+1<=end){
                ct(i+1,end,rightpnc);
            }
            else{
                rightpnc.push_back(NULL);
            }
            for(int j= 0;j<leftpnc.size();j++){
                for(int k=0;k<rightpnc.size();k++){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = leftpnc[j];
                    temp->right= rightpnc[k];
                    ans.push_back(temp);
                }
            }
        }
    }
};