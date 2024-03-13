class Solution {
public:
    int pivotInteger(int n) {
        int a,b;
        for(int i=1;i<=n;i++){
            a=i*(i+1)/2;
            b=n*(n+1)/2-a+i;
            if(a==b){
                return i;
            }
        }
        return -1;
    }
};