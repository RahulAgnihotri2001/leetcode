class Solution {
public:

    void func(int start,int end,string temp,vector<string> &final,string &s,unordered_set<string>&st){
        if(end==s.length()-1){
            if(st.find(s.substr(start,end-start+1))!=st.end()){
                if(start!=0){
                    temp=temp+" ";
                }
                temp=temp+s.substr(start,end-start+1);
                final.push_back(temp);
                return;
            }
            else{
                return;
            }
        }
        if(st.find(s.substr(start,end-start+1))!=st.end()){
            string x=temp;
            if(start!=0){
                    x=x+" ";    
            }
            x=x+s.substr(start,end-start+1);
            func(end+1,end+1,x,final,s,st);
        }
        func(start,end+1,temp,final,s,st);
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // ig no DP  but recursion will work
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        vector<string> final;
        int end=0;
        int start=0;
        string temp="";
        func(start,end,temp,final,s,st);
        return final;
    }
};