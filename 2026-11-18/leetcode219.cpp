//contains duplicate II
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
    public:
    bool containsNearbyDuplicate(vector<int>& nums,int k){
        unordered_map<int,int> map;
        int n=(int)nums.size();
        for(int i=0;i<n;++i){
            auto it=map.find(nums[i]);
            if(it==map.end())map[nums[i]]=i;
            else{
                if(i-it->second<=k)return true;
                else{
                    it->second=i;
                }
            }
        }
        return false;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    int k;
    cin>>k;
    Solution s;
    cout<<(s.containsNearbyDuplicate(nums,k)?"true":"false")<<endl;
    return 0;
}