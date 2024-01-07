class Solution {
public:
    int balancedStringSplit(string s) {
        int l1=0;
        int r1=0;
        int answer=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                r1++;
            }
            else{
                l1++;
            }
            if(l1==r1){
                answer++;
                l1=0;
                r1=0;
            }
        }
        return answer;
    }
};