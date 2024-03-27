class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; // Since product will always be greater than or equal to k

    int answer = 0;
    int start = 0;
    int product = 1;

    for (int end = 0; end < nums.size(); end++) {
        product *= nums[end];
        while (product >= k) {
            product /= nums[start];
            start++;
        }
        answer += (end - start + 1); // Add the number of subarrays ending at 'end'
    }
    return answer;
    }
};