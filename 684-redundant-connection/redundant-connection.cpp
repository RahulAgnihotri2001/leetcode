class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent;
        for(int i=0;i<edges.size();i++){
            parent.push_back(i+1);
        }
        vector<int> range(edges.size(),1);
        int answer1=-1,answer2=-1;
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(parent[a-1]==parent[b-1]){
                answer1=a;
                answer2=b;
            }
            else{
                if(range[parent[a-1]-1]>=range[parent[b-1]-1]){
                    range[parent[a-1]-1]=range[parent[a-1]-1]+range[parent[b-1]-1];
                    int c=parent[b-1];
                    for(int j=0;j<parent.size();j++){
                        if(parent[j]==c){
                            parent[j]=parent[a-1];
                        }
                    }
                }
                else{
                    range[parent[b-1]-1]=range[parent[b-1]-1]+range[parent[a-1]-1];
                    int c=parent[a-1];
                    for(int j=0;j<parent.size();j++){
                        if(parent[j]==c){
                            parent[j]=parent[b-1];
                        }
                    }
                }
            }
        }
        vector<int> answer;
        answer.push_back(answer1);
        answer.push_back(answer2);
        return answer;
    }
};