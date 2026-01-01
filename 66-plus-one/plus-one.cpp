class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer = digits;
        reverse(answer.begin(),answer.end());
        int carry=1;
        for(int i=0;i<answer.size();i++){
            if(carry==0){
                break;
            }
            int x = answer[i] + carry;
            answer[i]=x%10;
            carry=x/10;
        }
        if(carry!=0){
            answer.push_back(carry);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};