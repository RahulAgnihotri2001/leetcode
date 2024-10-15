class Solution {
public:
    long long minimumSteps(string s) {
        long long count1=0;
        for(long long i=0;i<s.length();i++){
            if(s[i]=='1'){
                count1++;
            }
        }
        long long answer=0;
        long long behind=0;
        for(long long i=0;i<s.length();i++){
            if(s[i]=='1'){
                long long a =s.length() -(count1-behind);
                answer=answer + a-i;
                behind++;
            }
        }
        return answer;
    }
};