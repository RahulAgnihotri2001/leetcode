class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int answer = INT_MIN;
        while(i<j){
            answer= max(min(height[j],height[i])*(j-i),answer);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return answer;
    }
};