class Solution {
public:
    string robotWithString(string s) {
        vector<char> temp;
        char x = 'z';
        for(int i=s.length()-1;i>=0;i--){
            temp.push_back(x);
            if(s[i]<x){
                x=s[i];
            }
        } 
        reverse(temp.begin(),temp.end());
        stack<char> st;
        string answer= "";
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            while(!st.empty() && st.top()<= temp[i]){
                answer.push_back(st.top());
                st.pop();
            }
        }
        while(!st.empty()){
           answer.push_back(st.top());
           st.pop(); 
        }
        return answer;
    }
};