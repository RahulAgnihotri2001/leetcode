class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1){
            return 1;
        }
        vector<int> temp(ratings.size(),0);
        for(int i=1;i<temp.size();i++){
            if(ratings[i]>ratings[i-1]){
                temp[i]=temp[i-1]+1;
            }
        }
        for(int i=temp.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                temp[i]= max(temp[i], temp[i+1]+1);
            }
        }
        int answer=0;
        for(int i=0;i<temp.size();i++){
            answer=answer+temp[i];
        }
        answer=answer+temp.size();
        return answer;

    }
};