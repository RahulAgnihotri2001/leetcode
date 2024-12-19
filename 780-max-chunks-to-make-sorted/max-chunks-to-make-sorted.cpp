class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int answer=0;
        int start=0;
        int mi=arr[0];
        int ma=arr[0];
        for(int i=0;i<arr.size();i++){
            mi=min(mi,arr[i]);
            ma=max(ma,arr[i]);
            if(mi==start && ma==i){
                answer++;
                start=i+1;
                if(i+1<arr.size()){
                    mi=arr[i+1];
                    ma=arr[i+1];
                }
                else{
                    break;
                }
            }
        }
        return answer;
    }
};