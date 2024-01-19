class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i=matrix.size();
        int j=matrix[0].size();
        int arr[i][j];
        for(int a=0;a<i;a++){
            for(int b=0;b<j;b++){
                arr[a][b]=INT_MAX;
            }
        }
        for(int k=0;k<j;k++){
            arr[0][k]=matrix[0][k];
        }
        for(int k=1;k<i;k++){
            for(int m=0;m<j;m++){
                if(m-1>=0){
                    arr[k][m]=min(arr[k][m],arr[k-1][m-1]+matrix[k][m]);
                }
                arr[k][m]=min(arr[k][m],arr[k-1][m]+matrix[k][m]);
                if(m+1<j){
                    arr[k][m]=min(arr[k][m],arr[k-1][m+1]+matrix[k][m]);
                }
            }
        }
        int ans=INT_MAX;
        for(int z=0;z<j;z++){
            ans=min(ans,arr[i-1][z]);
        }
        return ans;
    }
};