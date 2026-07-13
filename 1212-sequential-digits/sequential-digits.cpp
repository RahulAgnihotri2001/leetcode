class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        for(int start=1;start<=9;start++){
            int value = start;
            while(value <= high){
                if(value >= low){
                    answer.push_back(value);
                }
                int y = ((value%10)+1)%10;
                if(y==0){
                    break;
                }
                value = value*10 +y;
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};