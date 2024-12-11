class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       vector<int> start;
       vector<int> end;
       for(int i=0;i<nums.size();i++){
            start.push_back(nums[i]-k);
            end.push_back(nums[i]+k);
       } 
       sort(start.begin(),start.end());
       sort(end.begin(),end.end());
       int i=0,j=0;
       int answer=0;
       while(i<start.size()){
        if(start[i]<=end[j]){
            i++;
        }
        else{
            j++;
        }
        answer=max(answer,i-j);
       }
       return answer;
    }
};