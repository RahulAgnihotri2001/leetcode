class Solution {
public:


    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        //  m,n and mean
        //  mean*(m+n)-(sum of m) = sum of n numbers
        int summ=0;
        for(int i=0;i<rolls.size();i++){
            summ=summ+rolls[i];
        }
        int k=mean*(rolls.size()+n)-summ;
        // Now I want k sum with n throws
        vector<int> answer;
        if(k>6*n || k<n){
            return answer;
        }
        int a=k/n;
        for(int i=0;i<n;i++){
            answer.push_back(a);
        }
        int b=k%n;
        int i=0;
        while(b!=0){
            if(6-answer[i]>=b){
                answer[i]+=b;
                b=0;
            }
            else{
                b=b-(6-answer[i]);
                answer[i]=6;
                i++;
            }
        }
        return answer;
    }
};