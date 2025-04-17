class Solution {
public:

    int func(string s,int start, string temp,int index, set<string> &dict,vector<vector<int>> &dp){
        if(index>=s.length()){
            return index-start;
        }
        if(dp[start][index]!=-1){
            return dp[start][index];
        }
        if(dict.find(s.substr(start))!=dict.end()){
            return 0;
        }
        temp.push_back(s[index]);
        int a;
        if(dict.find(temp)!= dict.end()){
            string x="";
                        // Leleo
            a= min(func(s,index+1,x,index+1,dict,dp),func(s,start,temp,index+1,dict,dp));
        }
        else{
            string x="";
            a= min(func(s,index+1,x,index+1,dict,dp) + index-start+1,func(s,start,temp,index+1,dict,dp));
        }
        dp[start][index]=a;
        return dp[start][index];
    }


    int minExtraChar(string s, vector<string>& dictionary) {
        // With every char have following option =>  
        // if in dictionay = 1. Take it , 2. Dont't take it
        // if not in dictionary either drop present temp or add that char 
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        set<string> dict;
        for(int i=0;i<dictionary.size() ;i++){
        dict.insert(dictionary[i]);
        }
        int index=0;
        string temp="";
        int start=0;
        int answer = func(s,start,temp,index,dict,dp);
        return answer;
    }
};