class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> final, curr, curr1;
        for(int i=0;i<arr.size();i++){
            curr1= {arr[i]};
            for(auto it: curr){
                curr1.insert(it|arr[i]);
            }
            for(auto it: curr1){
                final.insert(it);
            }
            curr=curr1;
        }
        return final.size();
    }

};