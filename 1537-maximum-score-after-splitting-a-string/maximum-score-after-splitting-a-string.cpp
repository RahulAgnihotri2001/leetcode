class Solution {
public:
    int maxScore(string s) {
        if(s=="00"||s=="11"){
            return 1;
        }
        if(s=="01"){
            return 2;
        }
        vector<int> lefz;
        vector<int> righo;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                count++;
            }
            lefz.push_back(count);
        }
        if(count==s.length()){
            return count-1;
        }
        count=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                count++;
            }
            righo.push_back(count);
        }
        if(count==s.length()){
            return count-1;
        }
        reverse(righo.begin(),righo.end());
        int answer=0;
        for(int i=1;i<s.length()-1;i++){
            answer=max(answer,righo[i]+lefz[i]);
        }
        return answer;
    }
};