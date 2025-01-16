class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int answer=0;
        int a=nums1.size();
        int b=nums2.size();
        if(a%2==0 && b%2==0){
            return 0;
        }
        if(a%2==0){
           for(int i=0;i<nums1.size();i++){
               answer=answer^nums1[i];
           }
           return answer;
        } 
        if(b%2==0){
            for(int i=0;i<nums2.size();i++){
                answer=answer^nums2[i];
            }
            return answer;
        }

        for(int i=0;i<nums1.size();i++){
            answer=answer^nums1[i];
        }
         for(int j=0;j<nums2.size();j++){
                answer=answer^nums2[j];
        }
        return answer;
    }
};