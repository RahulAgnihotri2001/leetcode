class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> count;
       
        for(int i=0;i<bank.size();i++){
             int sum=0;
             for(int j=0;j<bank[i].length();j++){
                 if(bank[i][j]=='1'){
                     sum++;
                 }
             }
             count.push_back(sum);
        }
        int i=0;
        while(i<count.size() && count[i]==0){
            i++;
        }
        int end=i+1;
        while(end<count.size() && count[end]==0){
            end++;
        }
        int answer=0;
        while(end<count.size()){
            answer=answer+count[i]*count[end];
            i=end;
            end++;
            while(end<count.size() && count[end]==0){
            end++;
        }
        }
        return answer;
    }
};