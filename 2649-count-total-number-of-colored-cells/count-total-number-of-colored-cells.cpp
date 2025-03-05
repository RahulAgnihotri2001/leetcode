class Solution {
public:
    long long coloredCells(int n) {
        if(n==1){
            return 1;
        }
        long long answer=1;
        for(long long i=1;i<n;i++){
            answer = answer + 4*i;
        }
        
        return answer;
    }
};