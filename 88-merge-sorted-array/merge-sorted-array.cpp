class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        if(m==0){
            nums1 = nums2;
        }
        for(int i=m-1;i>=0;i--){
            nums1[n+i]=nums1[i];
        }
        int start2=0;
        int start1=n;
        for(int i=0;i<(n+m);i++){
            if(start1>=(m+n) || (start2<n && nums2[start2]<nums1[start1])){
                nums1[i]=nums2[start2];
                start2++;
            }
            else{
                nums1[i]=nums1[start1];
                start1++;
            }
        }
    }
};