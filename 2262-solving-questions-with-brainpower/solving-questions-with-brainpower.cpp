class Solution {
public:

    long long dp(int index,vector<vector<int>>& question,vector<long long> &vec){
        if(index>=question.size()){
            return 0;
        }
        if(vec[index]!=-1){
            return vec[index];
        }
        long long a=question[index][0]+dp(index+question[index][1]+1,question,vec);
        long long b=dp(index+1,question,vec);
        vec[index]=max(a,b);
        return vec[index];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> vec(questions.size(),-1);
        long long answer=dp(0,questions,vec);
        return answer;

    }
};