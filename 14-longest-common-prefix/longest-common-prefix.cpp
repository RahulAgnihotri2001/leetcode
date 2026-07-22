class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int minlen=strs[0].length();
        for(int i=0;i<strs.size()-1;i++){
            minlen=min(minlen,(int)strs[i].length());
        }
        int flag=0;
        for(int i=0;i<minlen;i++){
            char a= strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=a){
                    flag=1;
                }
            }
            if(flag==0){
                ans.push_back(a);
            }
            else{
                break;
            }
        }
        return ans;
    }
};