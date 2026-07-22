class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> bl;
        vector<int> br;
        int a=0;
        for(int i=0;i<height.size();i++){
            bl.push_back(a);
            a=max(a,height[i]);
        }
        a=0;
        for(int i=height.size()-1;i>=0;i--){
            br.push_back(a);
            a=max(a,height[i]);
        }
        reverse(br.begin(),br.end());
        int answer=0;
        for(int i=0;i<height.size();i++){
            if(height[i]<min(br[i],bl[i])){
                answer+= min(br[i],bl[i])-height[i];
            }
        }
        return answer;
    }
};