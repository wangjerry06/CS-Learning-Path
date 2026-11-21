//insert interval
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> insert(vector<vector<int>> intervals,vector<int>newInterval){
        int n=(int)intervals.size();
        vector<vector<int>> res;
        if(n==0)return {newInterval};
        int p=0;
        bool hasInsert=false;
        while(p<n){
            int start=intervals[p][0];
            int tail=intervals[p][1];
            if(!hasInsert){
                if(newInterval[1]<start){
                    res.push_back(newInterval);
                    hasInsert=true;
                }
                else if(newInterval[0]<=tail){
                    start=min(start,newInterval[0]);
                    tail=max(tail,newInterval[1]);
                    while(p+1<n&&tail>=intervals[p+1][0]){
                        tail=max(tail,intervals[p+1][1]);
                        ++p;
                    }
                    hasInsert=true;
                }
            }
            res.push_back({start,tail});
            ++p;
        }
        if(!hasInsert)res.push_back(newInterval);
        return res;
    }
};

int main(){
    int n;
    if(!(cin>>n))return 0;
    vector<vector<int>> intervals(n,vector<int>(2));
    for(int i=0;i<n;++i){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<int> newInterval(2);
    cin>>newInterval[0]>>newInterval[1];

    Solution sol;
    vector<vector<int>> res=sol.insert(intervals,newInterval);

    cout<<'[';
    for(int i=0;i<(int)res.size();++i){
        if(i)cout<<',';
        cout<<'['<<res[i][0]<<','<<res[i][1]<<']';
    }
    cout<<']'<<endl;
    return 0;
}