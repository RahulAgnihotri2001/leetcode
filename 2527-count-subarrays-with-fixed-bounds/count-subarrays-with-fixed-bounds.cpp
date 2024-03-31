class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long answer=0;
        bool minfound= false;
        bool maxfound=false;
        int minStart=0, maxStart=0, start=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK || nums[i]<minK){
                minfound=false;
                maxfound=false;
                start=i+1;
            }
            if(nums[i]==minK){
                minfound=true;
                minStart=i;
            }
            if(nums[i]==maxK){
                maxfound=true;
                maxStart=i;
            }
            if(minfound && maxfound){
                answer=answer+ min(maxStart,minStart)-start+1;
            }
        }
        return answer;

    }
};