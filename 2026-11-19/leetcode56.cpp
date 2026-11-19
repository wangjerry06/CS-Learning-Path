//merge interval
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end());
        int n=(int)intervals.size();
        vector<vector<int>> res;
        int start=0;
        while(start<n){
            int tail=start+1;
            int besttail=intervals[start][1];
            while(tail<n&&besttail>=intervals[tail][0]){
                besttail=max(besttail,intervals[tail][1]);
                tail++;
            }
            res.push_back({intervals[start][0],besttail});
            start=tail;
        }
        return res;
    }
};

int main(){
    int n;
    if(!(cin>>n)) return 0;
    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    Solution sol;
    vector<vector<int>> res=sol.merge(intervals);
    cout<<"[";
    for(int i=0;i<(int)res.size();i++){
        cout<<"["<<res[i][0]<<","<<res[i][1]<<"]";
        if(i+1<(int)res.size()) cout<<",";
    }
    cout<<"]"<<endl;
    return 0;
}