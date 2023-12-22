class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count=0;
        int count10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                count++;
            }
            else if(bills[i]==10){
                if(count<1){
                    return false;
                }
                count--;
                count10++;
            }
            else{
               if(count10>0 && count>0){
                   count10--;
                   count--;
               }
               else if(count>2){
                   count=count-3;
               }
               else{
                   return false;
               }
            }
        }
        return true;
    }
};