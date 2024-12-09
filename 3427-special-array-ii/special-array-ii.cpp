class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        //  Maintain an array containing special array ending at that point 
        //  for every query check the end (good array before it) if length greater then diff bw start and end
        vector<int> track_previous;
        int prev_flag=0;
        int count=1;
        track_previous.push_back(1);
        if(nums[0]%2==1){
            prev_flag=1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==0 && prev_flag==1){
                count++;
                prev_flag=0;
            }
            else if(nums[i]%2==1 && prev_flag==0){
                count++;
                prev_flag=1;
            }
            else{
                count=1;
                if(nums[i]%2==0){
                    prev_flag=0;
                }
                else{
                    prev_flag=1;
                }
            }
            track_previous.push_back(count);
        }
        vector<bool> answer;
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0];
            int b=queries[i][1];
            if(track_previous[b]>=b-a+1){
                answer.push_back(true);
            }
            else{
                answer.push_back(false);
            }
        }
        return answer;

    }
};