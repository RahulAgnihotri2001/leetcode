class Solution {
public:
    bool isValidSerialization(string pr) {
        int index = 0;
        int node = 0;
        int null = 0;
        while (index < pr.size()) {
            string temp = "";
            while (index < pr.size() && pr[index] != ',') {
                temp.push_back(pr[index]);
                index++;
            }
            if(index<pr.size()){
                index++;
            }
            if (temp == "#") {
                null++;
            }
            else{
                node++;
            }
            if(node+1==null && index!=pr.size()){
                return false;
            }
            if(node+1<null){
                return false;
            }
        }
        if(node+1==null){
            return true;
        }
        return false;
    }
};