//minimum number if arrows to burst ballons
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    int findMinArrowShots(vector<vector<int>>& points){
        int n=(int)points.size();
        sort(points.begin(),points.end());
        int p=0;
        vector<vector<int>> res;
        while(p<n){
            int start=points[p][0];
            int tail=points[p][1];
            while(p+1<n&&tail>=points[p+1][0]){
                start=max(start,points[p+1][0]);
                tail=min(tail,points[p+1][1]);
                ++p;
            }
            ++p;
            res.push_back({start,tail});
        }
        return (int)res.size();
    }
};

int main(){
    int n;
    if(!(cin>>n))return 0;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i=0;i<n;++i){
        cin>>points[i][0]>>points[i][1];
    }

    Solution sol;
    cout<<sol.findMinArrowShots(points)<<endl;
    return 0;
}