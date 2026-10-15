//3sum
#include<iostream>
#include<vector>
#include<algorithm>
class Solution{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> nums){
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> res;
        int n=(int)nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>0)break;//如果最小的都大于零，那不可能凑0
            if(i>0&&nums[i]==nums[i-1])continue;//去重1
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum<0)++l;
                else if(sum>0)--r;
                else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    while(l<r&&nums[l]==nums[l+1])++l;
                    while(l<r&&nums[r]==nums[r-1])--r;
                    ++l,--r;
                }
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    std::vector<int> nums={-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> res=s.threeSum(nums);

    std::cout<<"nums = [-1,0,1,2,-1,-4]\n";
    std::cout<<"count = "<<res.size()<<"\n";
    for(const auto& t:res){
        std::cout<<"["<<t[0]<<","<<t[1]<<","<<t[2]<<"]\n";
    }
    return 0;
}