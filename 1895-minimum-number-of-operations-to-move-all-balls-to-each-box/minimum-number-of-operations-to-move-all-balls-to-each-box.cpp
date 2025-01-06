class Solution {
public:
    vector<int> minOperations(string bo) {
        // Converting string into array of int
        vector<int> boxes;
        for(int i=0;i<bo.length();i++){
            boxes.push_back(bo[i]-'0');
        }
        vector<int> temp;
        // Operations to move every ball on left side of i th index to i th index 
        int count=0;
        int ball=0;
        for(int i=0;i<boxes.size();i++){
            temp.push_back(count);
            ball=ball+boxes[i];
            count=count+ball;
        }
        // Operations to move every ball on right side of i th index to i th index
        count=0;
        ball=0;
        for(int i=boxes.size()-1;i>=0;i--){
            temp[i]=temp[i]+ count;
            ball=ball+boxes[i];
            count=count+ball;
        }
        return temp;
    }
};