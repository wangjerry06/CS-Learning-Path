// Monotonic Array
#include<iostream>
#include<vector>

class Solution{
public:
    bool isMonotonic(std::vector<int>& nums){
        size_t count=nums.size();
        if(count<=2)return true;
        size_t i=0;
        while(i<count-1&&nums[i]==nums[i+1]){
            ++i;
        }
        if(i==count-1)return true;
        if(nums[i]<nums[i+1]){
            for(size_t j=0;j+1<count;++j){
                if(nums[j]>nums[j+1])return false;//!<=
            }
        }
        if(nums[i]>nums[i+1]){
            for(size_t j=0;j+1<count;++j){
                if(nums[j]<nums[j+1])return false;//!>=
            }
        }
        return true;
    }
};
int main(){
    int inp=0;
    std::vector<int> v;
    while(std::cin>>inp){
        v.push_back(inp);
    }
    Solution a;
    int res=a.isMonotonic(v);
    std::cout<<std::boolalpha<<res<<'\n';
    return 0;
}