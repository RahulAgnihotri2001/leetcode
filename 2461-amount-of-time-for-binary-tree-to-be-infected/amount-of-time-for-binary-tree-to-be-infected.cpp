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

    void inorder(TreeNode* root, map<int,vector<int>> &mp){
        if(root==NULL){
            return ;
        }
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            inorder(root->left,mp);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            inorder(root->right,mp);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        map<int,vector<int>> mp;
        inorder(root,mp);
        // 2 option  1) DFS from source   2) BFS from source
        //BFS
        int answer=0;
        unordered_set<int> se;
        stack<pair<int,int>> st;
        se.insert(start);
        st.push({start,0});
        while(!st.empty()){
            int x=st.top().first;
            int y=st.top().second;
            answer=max(answer,y);
            st.pop();
            for(auto it : mp[x]){
                if(se.find(it)==se.end()){
                    st.push({it,y+1});
                    se.insert(it);
                }
            }
        }
        return answer;
    }
};