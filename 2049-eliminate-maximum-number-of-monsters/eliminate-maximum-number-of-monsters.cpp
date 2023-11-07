class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int abhi=0;
        vector<double> vec;
        for(int i=0;i<dist.size();i++){
            double x= double(dist[i])/double(speed[i]);
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        int answer=0;
        /*
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        */
        cout<<endl;
        for(int i=0;i<vec.size();i++){
            if(abhi<vec[i]){
                answer++;
                abhi++;
            }
            else{
                break;
            }
        }
        return answer;
    }
};