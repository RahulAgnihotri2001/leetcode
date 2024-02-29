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
 /*
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qu;
        int level=0;
        int prev=0;
        // Level 0   i should be increasing
         qu.push(root);
        qu.push(NULL);
        while(!qu.empty()){
            TreeNode* temp=qu.front();
            qu.pop();
            if(temp!=NULL){
                if(level%2==0){
                    if(prev >= temp->val || temp->val % 2==0){
                        return false;
                    }
                    else{
                        prev=temp->val;
                    }
                }
                else{
                    if(prev <= temp->val || temp->val%2==1){
                        return false;
                    }
                    else{
                        prev=temp->val;
                    }
                }
            }
            else{
                if(!qu.empty()){
                    level=level+1;
                    if(level%2==0){
                        prev=INT_MAX;
                    }
                    else{
                        prev=0;
                    }
                    qu.push(NULL);
                }
            }
        }
        return true;

    }
};
*/
class Solution {
 
    unordered_map<int , int > m;
    
    bool dfs(TreeNode* root , int level ){
        
        if (root == NULL )  return true;
        
        if (level & 1){
            if ( root->val  &  1  )  return false; // if level is odd then value should not be odd
        }
        else if ( !(root->val & 1) ) return false; // if level is even then value should not be even
        
        
        if (m.find(level) != m.end() ){
            if (level & 1 ){
                if (m[level] <= root->val ) return false; // should be strictely strictly decreasing   
            }
            else if (m[level] >= root->val ) return false; // should be strictely strictly increasing  
            
        }
        
        m[level] =  root->val;
    
        return dfs(root->left , level + 1) && dfs(root->right, level +  1);
    }
    
    
public:
    bool isEvenOddTree(TreeNode* root) {
        
        return dfs(root, 0 );
        
        
    }
};