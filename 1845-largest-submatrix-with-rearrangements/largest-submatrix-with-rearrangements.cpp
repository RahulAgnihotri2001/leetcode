class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();
        for(int i=0;i<col;i++){
            int count=0;
            for(int j=0;j<row;j++){
                if(matrix[j][i]==1){
                    count++;
                }
                else{
                    count=0;
                }
                matrix[j][i]=count;
            }
        }
        for(int i=0;i<row;i++){
            sort(matrix[i].begin(),matrix[i].end());
        }
        int answer=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                answer=max(answer,matrix[i][j]*(col-j));
            }
        }
        return answer;
    }
};