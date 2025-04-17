class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1 have a length m+n;
        // Shift nums1 to extrime right
        for(int i=m-1;i>=0;i--){
            nums1[i+n]=nums1[i];
        }
        int start=0;
        int i=n;
        int j=0;
        while(i<m+n && j<n){
            if(nums1[i]<=nums2[j]){
                nums1[start]=nums1[i];
                i++;
            }
            else{
                nums1[start]=nums2[j];
                j++;
            }
            start++;
        }
        if(j<n){
            while(j<n){
                nums1[start]=nums2[j];
                j++;
                start++;
            }
        }
    }
};