class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        vector<int> answer;
        int summary=0;
        for(int i=0;i<nums.size();i++){
            summary=summary^nums[i];
        }
        int maximumBit=1;
        for(int i=0;i<mb;i++){
            maximumBit=maximumBit*2;
        }
        maximumBit--;
        // cout<<maximumBit<<" : "<<summary;
        for(int i=0;i<nums.size();i++){
            int a=summary^maximumBit;
            answer.push_back(a);
            summary=summary^nums[nums.size()-1-i];
        }
        return answer;
    }
};