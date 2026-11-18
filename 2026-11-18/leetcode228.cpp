//summary ranges
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
    public:
    vector<string> summaryRanges(vector<int>& nums){
        int n=(int)nums.size();
        vector<string> res;
        int l=0;
        while(l<n){
            int r=l;
            string str="";
            str+=to_string(nums[l]);
            while(r+1<n&&nums[r]+1==nums[r+1]){
                r++;
            }
            if(r>l){
                str+="->"+to_string(nums[r]);
            }
            res.push_back(str);
            l=r+1;
        }
        return res;
    }
};

int main(){
    int n;
    if(!(cin>>n)) return 0;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    vector<string> res=sol.summaryRanges(nums);

    cout<<"[";
    for(int i=0;i<(int)res.size();i++){
        if(i>0) cout<<",";
        cout<<"\""<<res[i]<<"\"";
    }
    cout<<"]"<<endl;
    return 0;
}