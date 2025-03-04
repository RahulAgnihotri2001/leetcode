class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>1){
            while(n%3==0){
                n=n/3;
            }
            if(n%3!=0){
                n=n-1;
                if(n%3!=0){
                    return false;
                }
            }
        }
        return true;
    }
};