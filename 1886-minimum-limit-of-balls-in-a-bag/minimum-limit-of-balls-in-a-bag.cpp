class Solution {
public:

    int func(int value, vector<int> &nums){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>value){
                int x=nums[i]/value;
                if(nums[i]%value==0){
                    count=count+x-1;
                }
                else{
                    count=count+x;
                }
            }
        }
        return count;
    }

    int minimumSize(vector<int>& nums, int maxOperation) {
      int maximum=0;
      for(int i=0;i<nums.size();i++){
          maximum=max(maximum,nums[i]);
      }  
      int start=1;
      int end=maximum;
      while(start<end){
          int mid=start+(end-start)/2;
          int count= func(mid,nums);
          // cout<<count<<" "<<mid<<endl;
          if(count<=maxOperation){
              end=mid;
          }
          else{
              start=mid+1;
          }
      }
      return start;
    }
};