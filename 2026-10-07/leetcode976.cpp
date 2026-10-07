//large perimeter triangle
#include<iostream>
#include<vector>
#include<algorithm>
//解题思路：给的数组中最优解一定是从大往小数的第一组符合条件的
class Solution{
    public:
    int largePerimeter(const std::vector<int>& nums){
        sort(nums.begin(),nums.end());
        size_t n=nums.size();
        for(size_t i=n-1;i>=2;--i){
            if(nums[i]<nums[i-1]+nums[i-2])return nums[i]+nums[i-1]+nums[i-2];
        }
        return 0;
    }
};
int main(){
    int x;
    std::vector<int> v;
    while(std::cin>>x)v.push_back(x);
    Solution A;
    std::cout<<A.largePerimeter(v)<<'\n';
    return 0;
}