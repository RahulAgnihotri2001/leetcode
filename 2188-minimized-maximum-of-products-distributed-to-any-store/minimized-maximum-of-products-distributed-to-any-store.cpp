class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        // Select a number count shop if shop less then n decrease number
        // start with max product 
        int  end=0;
        for(int i=0;i<quant.size();i++){
            end=max(end,quant[i]);
        }
        int start=1;
         while(start!=end){
            int mid=(end-start)/2+start;
            int count=0;
            int answer=0;
            for(int i=0;i<quant.size();i++){
                if(quant[i]<=mid){
                    answer++;
                }
                else{
                    if(quant[i]%mid==0){
                        answer = answer + quant[i]/mid;
                    }
                    else{
                        answer = answer + quant[i]/mid +1;
                    }
                }
            }
            if(answer>n){
                    start=mid+1;
                }
                else{
                    end=mid;
                }
         }
         return end;
    }
};