class Solution {
public:
    int fun(int n){
        if(n==1){
            return 0;
        }
        if(n%2==0){
            return 1+fun(n/2);
        }
        else{
            int a=fun(n-1);
            if(n==INT_MAX){
                return 32;
            }
            int b=fun(n+1);
            return min(a,b)+1;
        }
    }


    int integerReplacement(int n) {
        // write dp wala approch first then we will try something else;
        int answer=fun(n);
        return answer;
    }
};