class Solution {
public:

    int func(vector<int> &vec){
        vector<int> leftsmall;
        stack<int> st;
        for(int i=0;i<vec.size();i++){
            if(st.empty()){
                leftsmall.push_back(-1);
                st.push(i);
            }
            else{
                while(!st.empty() && vec[st.top()]>=vec[i]){
                    st.pop();
                }
                if(st.empty()){
                    leftsmall.push_back(-1);
                    st.push(i);
                }
                else{
                    leftsmall.push_back(st.top());
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> rightsmall;
        for(int i=vec.size()-1;i>=0;i--){
            if(st.empty()){
                rightsmall.push_back(vec.size());
                st.push(i);
            }
            else{
                while(!st.empty() && vec[st.top()]>=vec[i]){
                    st.pop();
                }
                if(st.empty()){
                    rightsmall.push_back(vec.size());
                    st.push(i);
                }
                else{
                    rightsmall.push_back(st.top());
                    st.push(i);
                }
            }
        }
        reverse(rightsmall.begin(),rightsmall.end());
        int answer=0;
        for(int i=0;i<vec.size();i++){
            cout<<leftsmall[i]<<" "<<rightsmall[i]<<" / ";
            answer=max(answer,(rightsmall[i]-leftsmall[i]-1)*vec[i]);
        }
        cout<<endl;
        return answer;
    }



    int maximalRectangle(vector<vector<char>>& mat) {
        vector<vector<int>> matrix(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat[0].size();i++){
            int temp=0;
            for(int j=0;j<mat.size();j++){
                if(mat[j][i]=='0'){
                    matrix[j][i]=0;
                    temp=0;
                }
                else{
                    temp++;
                    matrix[j][i]=temp;
                }
            }
        }
        /*
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j]<<" , ";
            }
            cout<<endl;
        }
        */
        int answer=0;
        for(int i=0;i<matrix.size();i++){
            int x=func(matrix[i]);
            cout<<x<<endl;
            answer=max(answer,x);
        }
        return answer;
    }
};