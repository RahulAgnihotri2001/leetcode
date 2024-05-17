class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=0;
        int pointer=0;
        int prev=INT_MAX;
        int count=0;
        int answer=0;
        while(pointer<nums.size()){
            if(nums[pointer]!=prev){
                nums[start]=nums[pointer];
                prev=nums[pointer];
                start++;
                count=1;
                pointer++;
                answer++;
            }
            else{
                if(count!=2){
                    nums[start]=nums[pointer];
                    start++;
                    count++;
                    pointer++;
                    answer++;
                }
                else{
                    pointer++;
                }
            }
        }
        return answer;
    }
};