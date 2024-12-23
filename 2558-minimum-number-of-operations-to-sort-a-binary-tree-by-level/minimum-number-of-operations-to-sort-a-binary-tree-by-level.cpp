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

    int func(vector<int>& temp){
        vector<pair<int,int>> vec;
        for(int i=0;i<temp.size();i++){
            vec.push_back({temp[i],i});
        }
        sort(vec.begin(),vec.end());
        int answer=0;
        for(int i=0;i<vec.size();i++){
            while(vec[i].second!=i){
                swap(vec[i],vec[vec[i].second]);
                answer++;
            }
        }
        return answer;
    }



    int minimumOperations(TreeNode* root) {
        // Do. level order Traversal and store it in a vector
        // Pass this vector to a function which will return a number
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(NULL);
        vector<int>temp;
        int answer=0;
        while(!qu.empty()){
            TreeNode* te= qu.front();
            qu.pop();
            if(te!=NULL){
                temp.push_back(te->val);
                if(te->left){
                    qu.push(te->left);
                }
                if(te->right){
                    qu.push(te->right);
                }
            }
            else{
                if(!qu.empty()){
                    qu.push(NULL);
                }
                answer=answer+func(temp);
                temp.clear();
            }
        }
        return answer;
    }
    
};