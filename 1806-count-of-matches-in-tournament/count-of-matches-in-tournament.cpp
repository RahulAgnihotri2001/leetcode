class Solution {
public:
    int numberOfMatches(int n) {
        int answer=0;
        while(n!=1){
            if(n%2==0){
                answer=answer+n/2;
                n=n/2;
            }
            else{
                answer=answer+(n-1)/2;
                n=n/2 +1;
            }
        }
        return answer;
    }
};