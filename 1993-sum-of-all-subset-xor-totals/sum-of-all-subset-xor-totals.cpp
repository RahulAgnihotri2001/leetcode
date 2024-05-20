class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int num=0;
        int index=0;
        int answer=0;
        func(index,num,answer,nums);
        return answer;
    }
    void func(int index,int num,int &answer,vector<int>& nums){
        if(index>=nums.size()){
            answer=answer+num;
            return;
        }
        // dont take 
        func(index+1,num,answer,nums);
        num=num^nums[index];
        func(index+1,num,answer,nums);
        return;
    }
};