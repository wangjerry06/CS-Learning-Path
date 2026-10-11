//Two Sum
#include<iostream>
#include<vector>
#include<unordered_map>
class Solution{
    public:
    std::vector<int> twoSum(std::vector<int>& nums,int target){
        std::unordered_map<int,int> m;
        for(int i=0;i<(int)nums.size();++i){
            int need=target-nums[i];
            auto it=m.find(need);
            if(it!=m.end()){
                std::vector<int> ans={it->second,i};
                return ans;
            }
            m[nums[i]]=i;
        }
        return {};
    }
};
int main(){
    std::vector<int> v={2,7,11,15};
    int target=9;
    Solution A;
    std::vector<int> ans=A.twoSum(v,target);
    for(int x:ans){
        std::cout<<x<<' ';
    }
    std::cout<<'\n';
    return 0;
}