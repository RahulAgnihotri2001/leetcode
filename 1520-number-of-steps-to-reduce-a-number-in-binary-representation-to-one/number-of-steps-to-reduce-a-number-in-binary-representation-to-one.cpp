class Solution {
public:
    int numSteps(string s) {
        // reverse the string
        reverse(s.begin(),s.end());
        int firstone=s.length()-1;
        int backzero=0;
        int index=0;
        while(index<s.length() && s[index]=='0'){
            backzero++;
            index++;
        }
        firstone=index;
        if(index==s.length()-1){
            return backzero;
        }
        int answer=backzero + 2;
        index++;
        int zero=0;
        int one=0;
        while(index<s.length()){
            if(s[index]=='1'){
                one++;
            }
            else{
                zero++;
            }
            index++;
        }
        answer=answer+(zero*2)+one;
        return answer;
    }
};