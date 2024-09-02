class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum=0;
        for(int i=0;i<chalk.size();i++){
            sum=sum+chalk[i];
            if(sum>k){
                return i;
            }
        }
        if(sum==k){
            return 0;
        }
        k=k%sum;
        sum=0;
        for(int i=0;i<chalk.size();i++){
            sum=sum+chalk[i];
            if(sum>k){
                return i;
            }
        }
        return 0;
    }
};