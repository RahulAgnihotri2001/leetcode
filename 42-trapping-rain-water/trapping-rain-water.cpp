class Solution {
public:
    int trap(vector<int>& height) {
        int arrleft[height.size()];
        int arrright[height.size()];
        int mal=0;
        for(int i=0;i<height.size();i++){
            arrleft[i]=mal;
            mal=max(height[i],mal);
        }
        int mar=0;
        for(int i=height.size()-1;i>=0;i--){
            arrright[i]=mar;
            mar=max(height[i],mar);
        }
        /*
        for(int i=0;i<height.size();i++){
            cout<<arrleft[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<height.size();i++){
            cout<<arrright[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<height.size();i++){
            cout<<height[i]<<" ";
        }
        */
        int sum=0;
        for(int i=0;i<height.size();i++){
            int left=arrleft[i];
            int right=arrright[i];
            if(left>height[i] && right>height[i]){
                sum=sum+min(left,right)-height[i];
            }
        }
        return sum;
    }
};