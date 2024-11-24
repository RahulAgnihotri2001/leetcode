class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count=0;
        int minimum=INT_MAX;
        long long answer=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                minimum=min(minimum,abs(matrix[i][j]));
                answer=answer+abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    count++;
                }
            }
        }
        if(count%2==0){
            return answer;
        }
        cout<<"Hello : "<<minimum;
        return answer-(2*minimum);
    }
};