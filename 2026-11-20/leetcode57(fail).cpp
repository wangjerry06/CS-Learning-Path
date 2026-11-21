//insert interval
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval){
        int n=(int)intervals.size();
        int p=0;
        vector<vector<int>> res;
        bool hasInsert=false;
        while(p<n){
            if(!hasInsert&&intervals[p][1]<newInterval[0]){
                res.push_back(intervals[p]);
                p++;
            }
            else if(!hasInsert&&intervals[p][0]>newInterval[1]){
                res.push_back(newInterval);
                res.push_back(intervals[p]);
                p++;
                hasInsert=true;
            }
            else if(hasInsert){
                res.push_back(intervals[p++]);
            }
            else{
                int start=min(intervals[p][0],newInterval[0]);
                int tail=max(intervals[p][1],newInterval[1]);
                res.push_back({start,tail});
                hasInsert=true;
                ++p;
            }
        }
        return res;
    }
};