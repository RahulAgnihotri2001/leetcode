class Solution {
public:
    int minOperations(vector<string>& logs) {
        int answer=0;
        for(int i=0;i<logs.size();i++){
            if(logs[i]=="../"){
                if(answer!=0){
                    answer--;
                }
            }
            else if(logs[i]=="./"){}
            else{
                answer++;
            }
        }
        return answer;

    }
};